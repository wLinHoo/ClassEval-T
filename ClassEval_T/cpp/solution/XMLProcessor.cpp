
#include <algorithm>
#include <iostream>

#include <string>
#include <vector>
#include "tinyxml.h"

class XMLProcessor {
public:
    XMLProcessor(const std::string& file_name);
    TiXmlNode* read_xml();
    bool write_xml(const std::string& file_name);
    bool process_xml_data(const std::string& file_name);
    std::vector<TiXmlElement*> find_element(const std::string& element_name);

    std::string file_name;
    TiXmlDocument doc;
};

XMLProcessor::XMLProcessor(const std::string& file_name) : file_name(file_name) {}

TiXmlNode* XMLProcessor::read_xml() {
    if (!doc.LoadFile(file_name.c_str())) {
        std::cerr << "Error: Could not load XML file: " << file_name << std::endl;
        return nullptr;
    }
    return doc.RootElement();
}

bool XMLProcessor::write_xml(const std::string& file_name) {
    return doc.SaveFile(file_name.c_str());
}

bool XMLProcessor::process_xml_data(const std::string& file_name) {
    TiXmlElement* root = doc.RootElement();
    if (root == nullptr) {
        std::cerr << "Error: No root element found." << std::endl;
        return false;
    }

    for (TiXmlElement* element = root->FirstChildElement("item"); element != nullptr; element = element->NextSiblingElement("item")) {
        const char* text = element->GetText();
        if (text) {
            std::string upper_text(text);
            std::transform(upper_text.begin(), upper_text.end(), upper_text.begin(), ::toupper);
            element->Clear(); 
            element->LinkEndChild(new TiXmlText(upper_text.c_str())); 
        }
    }
    return write_xml(file_name);
}

std::vector<TiXmlElement*> XMLProcessor::find_element(const std::string& element_name) {
    std::vector<TiXmlElement*> elements;
    TiXmlElement* root = doc.RootElement();
    if (root == nullptr) return elements;

    for (TiXmlElement* element = root->FirstChildElement(element_name.c_str()); element != nullptr; element = element->NextSiblingElement(element_name.c_str())) {
        elements.push_back(element);
    }
    return elements;
}
