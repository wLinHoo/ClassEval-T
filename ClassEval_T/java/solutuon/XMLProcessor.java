package org.example;

import org.w3c.dom.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class XMLProcessor {
    private String fileName;
    private Document document;

    public XMLProcessor(String fileName) {
        this.fileName = fileName;
        this.document = null;
    }

    public Document readXml() {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            this.document = builder.parse(new File(this.fileName));
            this.document.getDocumentElement().normalize();
            return this.document;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public boolean writeXml(String fileName) {
        if (fileName == null || fileName.isEmpty()) {
            return false;
        }
        try {
            if (this.document == null) {
                return false;
            }

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(this.document);
            StreamResult result = new StreamResult(new File(fileName));
            transformer.transform(source, result);
            return true;
        } catch (TransformerException e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean processXmlData(String fileName) {
        if (this.document == null) {
            return false;
        }

        NodeList items = this.document.getElementsByTagName("item");
        for (int i = 0; i < items.getLength(); i++) {
            Node item = items.item(i);
            if (item.getNodeType() == Node.ELEMENT_NODE) {
                Element element = (Element) item;
                element.setTextContent(element.getTextContent().toUpperCase());
            }
        }
        return writeXml(fileName);
    }

    public List<Element> findElement(String elementName) {
        List<Element> elements = new ArrayList<>();
        if (this.document == null) {
            return elements;
        }

        NodeList nodeList = this.document.getElementsByTagName(elementName);
        for (int i = 0; i < nodeList.getLength(); i++) {
            if (nodeList.item(i).getNodeType() == Node.ELEMENT_NODE) {
                elements.add((Element) nodeList.item(i));
            }
        }
        return elements;
    }

    public Document getDocument() {
        return document;
    }

    public void setDocument(Document document) {
        this.document = document;
    }
}
