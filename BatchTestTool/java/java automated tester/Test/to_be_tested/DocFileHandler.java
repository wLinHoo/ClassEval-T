package to_be_tested;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.Map;
import org.apache.poi.xwpf.usermodel.Document;
import org.apache.poi.xwpf.usermodel.ParagraphAlignment;
import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFParagraph;
import org.apache.poi.xwpf.usermodel.XWPFRun;
import com.lowagie.text.Document;
import com.lowagie.text.Font;
import com.lowagie.text.Paragraph;
import com.lowagie.text.pdf.PdfWriter;
import org.apache.poi.xwpf.usermodel.XWPFTable;
import org.apache.poi.xwpf.usermodel.XWPFTableCell;
import org.docx4j.openpackaging.exceptions.Docx4JException;
import org.docx4j.openpackaging.packages.WordprocessingMLPackage;
import org.docx4j.wml.Text;
import java.util.ArrayList;
import java.util.List;

public class DocFileHandler {

    public String filePath;

    public DocFileHandler(String filePath) {
        this.filePath = filePath;
    }

    public boolean writeText(String content, int fontSize, String alignment) {
        try {
            XWPFDocument doc = new XWPFDocument();
            XWPFParagraph paragraph = doc.createParagraph();
            XWPFRun run = paragraph.createRun();
            run.setText(content);
            run.setFontSize(fontSize);
            Map<String, ParagraphAlignment> alignmentOptions = new HashMap<>();
            alignmentOptions.put("left", ParagraphAlignment.LEFT);
            alignmentOptions.put("center", ParagraphAlignment.CENTER);
            alignmentOptions.put("right", ParagraphAlignment.RIGHT);
            ParagraphAlignment alignmentValue = alignmentOptions.get(alignment.toLowerCase());
            if (alignmentValue == null) {
                alignmentValue = ParagraphAlignment.LEFT;
            }
            paragraph.setAlignment(alignmentValue);
            FileOutputStream fos = new FileOutputStream(new File(filePath));
            doc.write(fos);
            fos.close();
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public boolean addHeading(String heading, int level) {
        try {
            Document document = new Document();
            PdfWriter.getInstance(document, new File(filePath));
            document.open();
            Font font = new Font();
            font.setSize(16);
            font.setStyle(Font.BOLD);
            Paragraph paragraph = new Paragraph(heading, font);
            paragraph.setAlignment(Paragraph.ALIGN_CENTER);
            document.add(paragraph);
            document.close();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public boolean addTable(String[][] data) {
        try {
            XWPFDocument doc = new XWPFDocument(new FileInputStream(new File(filePath)));
            XWPFTable table = doc.createTable(data.length, data[0].length);
            for (int i = 0; i < data.length; i++) {
                for (int j = 0; j < data[0].length; j++) {
                    XWPFTableCell cell = table.getCell(i, j);
                    cell.setText(String.valueOf(data[i][j]));
                }
            }
            doc.write(new FileOutputStream(new File(filePath)));
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public String readText() throws IOException, Docx4JException {
        WordprocessingMLPackage wordMLPackage = WordprocessingMLPackage.load(new FileInputStream(new File(filePath)));
        List<String> textList = new ArrayList<>();
        for (Object obj : wordMLPackage.getMainDocumentPart().getContent()) {
            if (obj instanceof org.docx4j.wml.Text) {
                Text text = (Text) obj;
                textList.add(text.getText());
            }
        }
        return String.join("\n", textList);
    }
}
