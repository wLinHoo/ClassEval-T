import com.github.javaparser.ParserConfiguration;
import com.github.javaparser.StaticJavaParser;
import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.Modifier;
import com.github.javaparser.ast.NodeList;
import com.github.javaparser.ast.body.*;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.time.LocalDateTime;
import java.util.concurrent.atomic.AtomicInteger;

public class AccessModifierFixer {

    // 统计计数器
    private static final AtomicInteger totalFiles = new AtomicInteger(0);
    private static final AtomicInteger successFiles = new AtomicInteger(0);
    private static final AtomicInteger errorFiles = new AtomicInteger(0);
    private static final Path ERROR_LOG = Paths.get("modification_errors.log");

    static {
        StaticJavaParser.getConfiguration()
                .setLanguageLevel(ParserConfiguration.LanguageLevel.JAVA_17)
                .setLexicalPreservationEnabled(false);
    }

    public static void main(String[] args) {
        try {
            Path rootPath = Paths.get("C:/Users/admin/Desktop/java/111/untitled2/Test/to_be_tested")
                    .toAbsolutePath()
                    .normalize();

            if (!validatePath(rootPath)) return;
            System.out.println("开始处理目录: " + rootPath);
            Files.deleteIfExists(ERROR_LOG);

            Files.walk(rootPath)
                    .parallel()
                    .filter(Files::isRegularFile)
                    .filter(p -> p.toString().endsWith(".java"))
                    .forEach(AccessModifierFixer::processFile);

            printStatistics();
        } catch (IOException e) {
            System.err.println("初始化错误: " + e.getMessage());
        }
    }

    private static boolean validatePath(Path path) {
        if (!Files.exists(path)) {
            System.err.println("错误: 路径不存在 - " + path);
            return false;
        }
        if (!Files.isDirectory(path)) {
            System.err.println("错误: 路径不是目录 - " + path);
            return false;
        }
        return true;
    }

    private static void processFile(Path filePath) {
        totalFiles.incrementAndGet();
        try {
            if (!Files.isWritable(filePath)) {
                logError(filePath, "文件不可写");
                return;
            }

            System.out.println("正在处理: " + filePath.normalize());
            String content = Files.readString(filePath, StandardCharsets.UTF_8);
            CompilationUnit cu = StaticJavaParser.parse(content);

            // 类处理
            cu.findAll(ClassOrInterfaceDeclaration.class).forEach(cls -> {
                if (!cls.isPublic()) {
                    NodeList<Modifier> modifiers = cls.getModifiers().stream()
                            .filter(m -> !isRestrictedModifier(m))
                            .collect(NodeList.toNodeList());
                    modifiers.addFirst(new Modifier(Modifier.Keyword.PUBLIC));
                    cls.setModifiers(modifiers);
                }
            });

            // 字段处理
            cu.findAll(FieldDeclaration.class).forEach(field -> {
                boolean isPublic = field.getModifiers().stream()
                        .anyMatch(m -> m.getKeyword() == Modifier.Keyword.PUBLIC);

                if (!isPublic) {
                    // 创建新的修饰符列表
                    NodeList<Modifier> newModifiers = new NodeList<>();

                    // 保留非访问修饰符（如static/final等）
                    field.getModifiers().forEach(m -> {
                        if (!isAccessModifier(m)) {
                            newModifiers.add(m.clone());
                        }
                    });

                    // 添加public修饰符
                    newModifiers.addFirst(new Modifier(Modifier.Keyword.PUBLIC));
                    field.setModifiers(newModifiers);

                    System.out.println("已修复字段: " + field);
                }
            });


            // 新增方法处理
            cu.findAll(MethodDeclaration.class).forEach(method -> {
                if (hasRestrictedModifier(method.getModifiers())) {
                    NodeList<Modifier> modifiers = method.getModifiers().stream()
                            .filter(m -> !isRestrictedModifier(m))
                            .collect(NodeList.toNodeList());
                    modifiers.addFirst(new Modifier(Modifier.Keyword.PUBLIC));
                    method.setModifiers(modifiers);
                }
            });

            Files.writeString(
                    filePath,
                    cu.toString(),
                    StandardCharsets.UTF_8,
                    StandardOpenOption.WRITE,
                    StandardOpenOption.TRUNCATE_EXISTING
            );
            successFiles.incrementAndGet();

        } catch (com.github.javaparser.ParseProblemException e) {
            handleParseError(filePath, e);
        } catch (IOException e) {
            handleIOError(filePath, e);
        } catch (Exception e) {
            handleGenericError(filePath, e);
        }
    }

    // 以下静态方法需要保持与原始实现一致
    private static boolean hasRestrictedModifier(NodeList<Modifier> modifiers) {
        return modifiers.stream().anyMatch(AccessModifierFixer::isRestrictedModifier);
    }

    private static boolean isRestrictedModifier(Modifier modifier) {
        Modifier.Keyword keyword = modifier.getKeyword();
        return keyword == Modifier.Keyword.PRIVATE || keyword == Modifier.Keyword.PROTECTED;
    }

    private static void logError(Path path, String message) {
        try {
            String logEntry = String.format("[%s] %s - %s%n",
                    LocalDateTime.now(),
                    path.normalize(),
                    message);
            Files.writeString(ERROR_LOG, logEntry,
                    StandardOpenOption.CREATE,
                    StandardOpenOption.APPEND);
        } catch (IOException logEx) {
            System.err.println("无法写入错误日志: " + logEx.getMessage());
        }
    }

    private static void handleParseError(Path path, com.github.javaparser.ParseProblemException e) {
        String errorMsg = e.getProblems().get(0).getMessage();
        System.err.println("解析错误: " + path + " - " + errorMsg);
        logError(path, "语法错误: " + errorMsg);
        errorFiles.incrementAndGet();
    }

    private static void handleIOError(Path path, IOException e) {
        System.err.println("IO错误: " + path + " - " + e.getMessage());
        logError(path, "IO异常: " + e.getMessage());
        errorFiles.incrementAndGet();
    }

    private static void handleGenericError(Path path, Exception e) {
        System.err.println("未知错误: " + path + " - " + e.getMessage());
        logError(path, "未知异常: " + e.getMessage());
        errorFiles.incrementAndGet();
    }
    // 新增辅助方法
    private static boolean isAccessModifier(Modifier modifier) {
        Modifier.Keyword kw = modifier.getKeyword();
        return kw == Modifier.Keyword.PUBLIC
                || kw == Modifier.Keyword.PROTECTED
                || kw == Modifier.Keyword.PRIVATE;
    }

    private static void printStatistics() {
        System.out.println("\n处理结果统计:");
        System.out.println("总文件数: " + totalFiles.get());
        System.out.println("成功处理: " + successFiles.get());
        System.out.println("失败文件: " + errorFiles.get());
        System.out.println("错误日志: " + ERROR_LOG.toAbsolutePath());
    }
}