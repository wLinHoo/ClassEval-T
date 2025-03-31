#include <gtest/gtest.h>
#include "pch.h"
#include <fstream>
#include <iostream>


class XMLProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
        std::remove("test.xml");
        std::remove("output.xml");
        std::remove("processed.xml");
    }

    void create_test_file() {
        TiXmlDocument xmlDocument;

        
        xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

        
        TiXmlElement* xmlRoot = new TiXmlElement("root");
        xmlDocument.LinkEndChild(xmlRoot);

        
        TiXmlElement* xmlChild1 = new TiXmlElement("item");
        xmlRoot->LinkEndChild(xmlChild1);
        xmlChild1->LinkEndChild(new TiXmlText("apple"));

        TiXmlElement* xmlChild2 = new TiXmlElement("item");
        xmlRoot->LinkEndChild(xmlChild2);
        xmlChild2->LinkEndChild(new TiXmlText("banana"));

        TiXmlElement* xmlChild3 = new TiXmlElement("item");
        xmlRoot->LinkEndChild(xmlChild3);
        xmlChild3->LinkEndChild(new TiXmlText("orange"));

        
        xmlDocument.SaveFile("test.xml");
    }
};

TEST_F(XMLProcessorTest, TestXMLProcessor) {
    create_test_file();
    XMLProcessor processor("test.xml");

    
    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::vector<TiXmlElement*> lst = processor.find_element("item");
    ASSERT_EQ(lst.size(), 3);

    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "banana");
    ASSERT_EQ(std::string(lst[2]->GetText()), "orange");

    
    std::string file_name = "output.xml";
    bool result = processor.write_xml(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst1 = processor1.find_element("item");
    ASSERT_EQ(lst1.size(), 3);

    ASSERT_EQ(std::string(lst1[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst1[1]->GetText()), "banana");
    ASSERT_EQ(std::string(lst1[2]->GetText()), "orange");

    std::remove("output.xml");

    
    std::string file_name_processed = "processed.xml";
    result = processor.process_xml_data(file_name_processed);
    ASSERT_TRUE(result);

    XMLProcessor processor2(file_name_processed);
    TiXmlNode* root2 = processor2.read_xml();
    ASSERT_NE(root2, nullptr);

    std::vector<TiXmlElement*> lst2 = processor2.find_element("item");
    ASSERT_EQ(lst2.size(), 3);

    ASSERT_EQ(std::string(lst2[0]->GetText()), "APPLE");
    ASSERT_EQ(std::string(lst2[1]->GetText()), "BANANA");
    ASSERT_EQ(std::string(lst2[2]->GetText()), "ORANGE");

    std::remove("processed.xml");

    
    processor.read_xml();
    std::vector<TiXmlElement*> elements = processor.find_element("item");
    ASSERT_EQ(elements.size(), 3);
    ASSERT_EQ(std::string(elements[0]->GetText()), "apple");
    ASSERT_EQ(std::string(elements[1]->GetText()), "banana");
    ASSERT_EQ(std::string(elements[2]->GetText()), "orange");

}

#include <gtest/gtest.h>
#include <tinyxml.h>
#include <fstream>
#include <string>


void create_test_file(const std::string& xml_content) {
    std::ofstream ofs("test.xml");
    if (ofs.is_open()) {
        ofs << xml_content;
        ofs.close();
    }
    else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
}

class XMLProcessorTestReadXml : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {
        std::remove("test.xml");
    }
};

TEST_F(XMLProcessorTestReadXml, test_read_xml_1) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::vector<TiXmlElement*> lst = processor.find_element("item");
    ASSERT_EQ(lst.size(), 3);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "banana");
    ASSERT_EQ(std::string(lst[2]->GetText()), "orange");
}

TEST_F(XMLProcessorTestReadXml, test_read_xml_2) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("aaa"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("bbb"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("ccc"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::vector<TiXmlElement*> lst = processor.find_element("item");
    ASSERT_EQ(lst.size(), 3);
    ASSERT_EQ(std::string(lst[0]->GetText()), "aaa");
    ASSERT_EQ(std::string(lst[1]->GetText()), "bbb");
    ASSERT_EQ(std::string(lst[2]->GetText()), "ccc");
}

TEST_F(XMLProcessorTestReadXml, test_read_xml_3) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::vector<TiXmlElement*> lst = processor.find_element("item");
    ASSERT_EQ(lst.size(), 1);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
}

TEST_F(XMLProcessorTestReadXml, test_read_xml_4) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::vector<TiXmlElement*> lst = processor.find_element("item");
    ASSERT_EQ(lst.size(), 2);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "banana");
}

TEST_F(XMLProcessorTestReadXml, test_read_xml_5) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::vector<TiXmlElement*> lst = processor.find_element("item");
    ASSERT_EQ(lst.size(), 2);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "orange");
}

TEST_F(XMLProcessorTestReadXml, test_read_xml_6) {
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_EQ(root, nullptr);
}


class XMLProcessorTestWriteXml : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
        std::remove("test.xml");
        std::remove("output.xml");
        std::remove("processed.xml");
    }
};

TEST_F(XMLProcessorTestWriteXml, test_write_xml_1) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "output.xml";
    bool result = processor.write_xml(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 3);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "banana");
    ASSERT_EQ(std::string(lst[2]->GetText()), "orange");

    std::remove("output.xml");
    std::remove("test.xml");
}

TEST_F(XMLProcessorTestWriteXml, test_write_xml_2) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "output.xml";
    bool result = processor.write_xml(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 2);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "banana");

    std::remove("output.xml");
    std::remove("test.xml");
}

TEST_F(XMLProcessorTestWriteXml, test_write_xml_3) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "output.xml";
    bool result = processor.write_xml(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 1);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");

    std::remove("output.xml");
    std::remove("test.xml");
}

TEST_F(XMLProcessorTestWriteXml, test_write_xml_4) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("aaa"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("bbb"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("ccc"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "output.xml";
    bool result = processor.write_xml(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 3);
    ASSERT_EQ(std::string(lst[0]->GetText()), "aaa");
    ASSERT_EQ(std::string(lst[1]->GetText()), "bbb");
    ASSERT_EQ(std::string(lst[2]->GetText()), "ccc");

    std::remove("output.xml");
    std::remove("test.xml");
}

TEST_F(XMLProcessorTestWriteXml, test_write_xml_5) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "output.xml";
    bool result = processor.write_xml(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 2);
    ASSERT_EQ(std::string(lst[0]->GetText()), "apple");
    ASSERT_EQ(std::string(lst[1]->GetText()), "orange");

    std::remove("output.xml");
    std::remove("test.xml");
}

TEST_F(XMLProcessorTestWriteXml, test_write_xml_6) {
    XMLProcessor processor("");  

    bool result = processor.write_xml("");
    ASSERT_FALSE(result);
}

class XMLProcessorTestProcessXmlData : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {
        std::remove("processed.xml");
        std::remove("test.xml");
    }
};

TEST_F(XMLProcessorTestProcessXmlData, test_process_xml_data_1) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "processed.xml";
    bool result = processor.process_xml_data(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 3);
    ASSERT_EQ(std::string(lst[0]->GetText()), "APPLE");
    ASSERT_EQ(std::string(lst[1]->GetText()), "BANANA");
    ASSERT_EQ(std::string(lst[2]->GetText()), "ORANGE");
}

TEST_F(XMLProcessorTestProcessXmlData, test_process_xml_data_2) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "processed.xml";
    bool result = processor.process_xml_data(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 2);
    ASSERT_EQ(std::string(lst[0]->GetText()), "APPLE");
    ASSERT_EQ(std::string(lst[1]->GetText()), "BANANA");
}

TEST_F(XMLProcessorTestProcessXmlData, test_process_xml_data_3) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));
    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "processed.xml";
    bool result = processor.process_xml_data(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 1);
    ASSERT_EQ(std::string(lst[0]->GetText()), "APPLE");
}

TEST_F(XMLProcessorTestProcessXmlData, test_process_xml_data_4) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "processed.xml";
    bool result = processor.process_xml_data(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 2);
    ASSERT_EQ(std::string(lst[0]->GetText()), "APPLE");
    ASSERT_EQ(std::string(lst[1]->GetText()), "ORANGE");
}

TEST_F(XMLProcessorTestProcessXmlData, test_process_xml_data_5) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("aaa"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("bbb"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("ccc"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string file_name = "processed.xml";
    bool result = processor.process_xml_data(file_name);
    ASSERT_TRUE(result);

    XMLProcessor processor1(file_name);
    TiXmlNode* root1 = processor1.read_xml();
    ASSERT_NE(root1, nullptr);

    std::vector<TiXmlElement*> lst = processor1.find_element("item");
    ASSERT_EQ(lst.size(), 3);
    ASSERT_EQ(std::string(lst[0]->GetText()), "AAA");
    ASSERT_EQ(std::string(lst[1]->GetText()), "BBB");
    ASSERT_EQ(std::string(lst[2]->GetText()), "CCC");
}

class XMLProcessorTestFindElement : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {
        std::remove("test.xml");
    }
};

TEST_F(XMLProcessorTestFindElement, test_find_element_1) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string element_name = "item";
    std::vector<TiXmlElement*> elements = processor.find_element(element_name);
    ASSERT_EQ(elements.size(), 3);
    ASSERT_EQ(std::string(elements[0]->GetText()), "apple");
    ASSERT_EQ(std::string(elements[1]->GetText()), "banana");
    ASSERT_EQ(std::string(elements[2]->GetText()), "orange");
}

TEST_F(XMLProcessorTestFindElement, test_find_element_2) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("banana"));
    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string element_name = "item";
    std::vector<TiXmlElement*> elements = processor.find_element(element_name);
    ASSERT_EQ(elements.size(), 2);
    ASSERT_EQ(std::string(elements[0]->GetText()), "apple");
    ASSERT_EQ(std::string(elements[1]->GetText()), "banana");
}

TEST_F(XMLProcessorTestFindElement, test_find_element_3) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));
    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);

    std::string element_name = "item";
    std::vector<TiXmlElement*> elements = processor.find_element(element_name);
    ASSERT_EQ(elements.size(), 1);
    ASSERT_EQ(std::string(elements[0]->GetText()), "apple");
}

TEST_F(XMLProcessorTestFindElement, test_find_element_4) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("apple"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("orange"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);


    std::string element_name = "item";
    std::vector<TiXmlElement*> elements = processor.find_element(element_name);
    ASSERT_EQ(elements.size(), 2);
    ASSERT_EQ(std::string(elements[0]->GetText()), "apple");
    ASSERT_EQ(std::string(elements[1]->GetText()), "orange");
}

TEST_F(XMLProcessorTestFindElement, test_find_element_5) {
    TiXmlDocument xmlDocument;

    
    xmlDocument.LinkEndChild(new TiXmlDeclaration("1.0", "UTF-8", ""));

    
    TiXmlElement* xmlRoot = new TiXmlElement("root");
    xmlDocument.LinkEndChild(xmlRoot);

    
    TiXmlElement* xmlChild1 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild1);
    xmlChild1->LinkEndChild(new TiXmlText("aaa"));

    TiXmlElement* xmlChild2 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild2);
    xmlChild2->LinkEndChild(new TiXmlText("bbb"));

    TiXmlElement* xmlChild3 = new TiXmlElement("item");
    xmlRoot->LinkEndChild(xmlChild3);
    xmlChild3->LinkEndChild(new TiXmlText("ccc"));

    
    xmlDocument.SaveFile("test.xml");
    XMLProcessor processor("test.xml");

    TiXmlNode* root = processor.read_xml();
    ASSERT_NE(root, nullptr);


    std::string element_name = "item";
    std::vector<TiXmlElement*> elements = processor.find_element(element_name);
    ASSERT_EQ(elements.size(), 3);
    ASSERT_EQ(std::string(elements[0]->GetText()), "aaa");
    ASSERT_EQ(std::string(elements[1]->GetText()), "bbb");
    ASSERT_EQ(std::string(elements[2]->GetText()), "ccc");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}