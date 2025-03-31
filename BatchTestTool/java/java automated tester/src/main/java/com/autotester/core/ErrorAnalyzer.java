package com.autotester.core;

import javax.tools.*;
import java.io.IOException;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;
import java.util.stream.Collectors;

public class ErrorAnalyzer {
    private final Map<String, Integer> errorCounts = new LinkedHashMap<>();
    private final Map<Path, Set<String>> fileErrors = new HashMap<>();

    public ErrorAnalyzer() {
        // 初始化错误分类字典
        String[] errorTypes = {
                "照搬其它语言的第三方库",
                "缺少必要的库",
                "API与库版本不匹配",
                "函数调用与库不匹配",
                "API与预期功能不匹配",
                "导入错误的模块",
                "保留源语言语法",
                "符号错误",
                "语法结构",
                "语言特性错误",
                "类型转换错误",
                "缺少返回值的函数",
                "返回值类型与函数类型不匹配",
                "试图调用不存在的函数",
                "试图调用未定义的变量",
                "函数中的参数类型没有声明",
                "生成的代码前后矛盾",
                "生成非代码内容",
                "生成的代码不完整",
                "其他错误"
        };

        for (String type : errorTypes) {
            errorCounts.put(type, 0);
        }
    }

    public void analyzeDirectory(Path dir) throws IOException {
        List<Path> javaFiles = Files.walk(dir)
                .filter(p -> p.toString().endsWith(".java"))
                .collect(Collectors.toList());

        if (javaFiles.isEmpty()) {
            System.out.println("没有找到Java文件");
            return;
        }

        compileAndAnalyze(javaFiles);
    }

    private void compileAndAnalyze(List<Path> javaFiles) {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        if (compiler == null) {
            System.err.println("错误：需要在JDK环境下运行，而不是JRE");
            return;
        }

        DiagnosticCollector<JavaFileObject> diagnostics = new DiagnosticCollector<>();
        try (StandardJavaFileManager fileManager = compiler.getStandardFileManager(null, null, null)) {
            Iterable<? extends JavaFileObject> compilationUnits =
                    fileManager.getJavaFileObjectsFromPaths(javaFiles);

            JavaCompiler.CompilationTask task = compiler.getTask(
                    null, fileManager, diagnostics, null, null, compilationUnits);

            if (!task.call()) {
                processDiagnostics(diagnostics);
            }
        } catch (IOException e) {
            System.err.println("文件处理错误: " + e.getMessage());
        }
    }

    private void processDiagnostics(DiagnosticCollector<JavaFileObject> diagnostics) {
        for (Diagnostic<? extends JavaFileObject> diagnostic : diagnostics.getDiagnostics()) {
            JavaFileObject source = diagnostic.getSource();
            if (source == null) continue;

            Path filePath = Paths.get(source.toUri());
            String errorMsg = diagnostic.getMessage(Locale.ENGLISH);
            String errorType = classifyError(errorMsg);

            fileErrors.computeIfAbsent(filePath, k -> new HashSet<>()).add(errorType);
        }

        // 汇总统计结果
        for (Set<String> errors : fileErrors.values()) {
            for (String error : errors) {
                errorCounts.put(error, errorCounts.getOrDefault(error, 0) + 1);
            }
        }
    }

    private String classifyError(String errorMsg) {
        // 实现错误分类逻辑
        if (errorMsg.contains("cannot find symbol")) {
            return analyzeSymbolError(errorMsg);
        } else if (errorMsg.contains("package") && errorMsg.contains("does not exist")) {
            return analyzePackageError(errorMsg);
        } else if (errorMsg.contains("incompatible types")) {
            return analyzeTypeMismatch(errorMsg);
        } else if (errorMsg.contains("cannot be applied to given types")) {
            return "函数调用与库不匹配";
        } else if (errorMsg.contains("missing return statement")) {
            return "缺少返回值的函数";
        } else if (errorMsg.contains("expected")) {
            return analyzeSyntaxError(errorMsg);
        } else if (errorMsg.contains("overridden method does not throw")) {
            return "API与库版本不匹配";
        } else if (errorMsg.contains("cannot resolve method")) {
            return "试图调用不存在的函数";
        }
        return "其他错误";
    }

    private String analyzeSymbolError(String errorMsg) {
        Matcher matcher = Pattern.compile("symbol:\\s+(class|interface|variable|method)\\s+([\\w.]+)")
                .matcher(errorMsg);
        if (matcher.find()) {
            String type = matcher.group(1);
            String name = matcher.group(2);

            if (type.equals("class") || type.equals("interface")) {
                return isThirdParty(name) ? "缺少必要的库" : "导入错误的模块";
            } else if (type.equals("variable")) {
                return "试图调用未定义的变量";
            } else if (type.equals("method")) {
                return "试图调用不存在的函数";
            }
        }
        return "符号错误";
    }

    private String analyzePackageError(String errorMsg) {
        Matcher matcher = Pattern.compile("package (\\S+) does not exist").matcher(errorMsg);
        return matcher.find() && isThirdParty(matcher.group(1)) ?
                "缺少必要的库" : "导入错误的模块";
    }

    private String analyzeTypeMismatch(String errorMsg) {
        return errorMsg.contains("return") ?
                "返回值类型与函数类型不匹配" : "类型转换错误";
    }

    private String analyzeSyntaxError(String errorMsg) {
        return errorMsg.contains("';' expected") ?
                "保留源语言语法" : "语法结构";
    }

    private boolean isThirdParty(String identifier) {
        return identifier.startsWith("com.") ||
                identifier.startsWith("org.") ||
                identifier.startsWith("net.");
    }

    public void printResults() {
        System.out.println("错误统计结果：");
        errorCounts.forEach((k, v) -> System.out.println(k + ": " + v));
    }

    public static void main(String[] args) throws IOException {
        ErrorAnalyzer analyzer = new ErrorAnalyzer();
        analyzer.analyzeDirectory(Paths.get("C:\\Users\\admin\\Desktop\\java\\111\\untitled2\\Test\\to_be_tested"));
        analyzer.printResults();
    }
}