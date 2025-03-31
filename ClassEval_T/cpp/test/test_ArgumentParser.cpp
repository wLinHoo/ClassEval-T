#include <gtest/gtest.h>
#include "pch.h"


class ArgumentParserTestParseArguments : public ::testing::Test {
protected:
    ArgumentParser parser;

    void SetUp() override {
        
    }
};


TEST_F(ArgumentParserTestParseArguments, ParseArgumentsKeyValue) {
    std::string command_str = "script --name=John --age=25";
    parser.add_argument("name");
    parser.add_argument("age", false, "int");

    auto result_tuple = parser.parse_arguments(command_str);
    bool result = std::get<0>(result_tuple);
    auto missing_args = std::get<1>(result_tuple);

    EXPECT_TRUE(result);
    EXPECT_TRUE(missing_args.empty());
    EXPECT_EQ(parser.get_argument("name"), "John");
    EXPECT_EQ(parser.get_argument("age"), "25");
}


TEST_F(ArgumentParserTestParseArguments, ParseArgumentsSwitches) {
    std::string command_str = "script --verbose -d";
    parser.add_argument("verbose", false, "bool");
    parser.add_argument("d", false, "bool");

    auto result_tuple = parser.parse_arguments(command_str);
    bool result = std::get<0>(result_tuple);
    auto missing_args = std::get<1>(result_tuple);

    EXPECT_TRUE(result);
    EXPECT_TRUE(missing_args.empty());
    EXPECT_EQ(parser.get_argument("verbose"), "1");
    EXPECT_EQ(parser.get_argument("d"), "1");
}


TEST_F(ArgumentParserTestParseArguments, ParseArgumentsMissingRequired) {
    std::string command_str = "script --name=John";
    parser.add_argument("name");
    parser.add_argument("age", true, "int");

    auto result_tuple = parser.parse_arguments(command_str);
    bool result = std::get<0>(result_tuple);
    auto missing_args = std::get<1>(result_tuple);

    EXPECT_FALSE(result);
    EXPECT_EQ(missing_args, std::set<std::string>{"age"});
}

TEST_F(ArgumentParserTestParseArguments, ParseArgumentsOptional) {
    std::string command_str = "script --name=John";
    parser.add_argument("name");
    parser.add_argument("age", false, "int");

    auto result_tuple = parser.parse_arguments(command_str);
    bool result = std::get<0>(result_tuple);
    auto missing_args = std::get<1>(result_tuple);

    EXPECT_TRUE(result);
    EXPECT_TRUE(missing_args.empty());
}

TEST_F(ArgumentParserTestParseArguments, ParseArgumentsDefault) {
    std::string command_str = "script --name=John";
    parser.add_argument("name");
    parser.add_argument("age", false, "int");

    auto result_tuple = parser.parse_arguments(command_str);
    bool result = std::get<0>(result_tuple);
    auto missing_args = std::get<1>(result_tuple);

    EXPECT_TRUE(result);
    EXPECT_TRUE(missing_args.empty());
}


class ArgumentParserTestGetArgument : public ::testing::Test {
protected:
    ArgumentParser parser;

    void SetUp() override {
        
    }
};

TEST_F(ArgumentParserTestGetArgument, GetArgumentExists) {
    parser.arguments = { {"name", "John"} };
    std::string result = parser.get_argument("name");
    EXPECT_EQ(result, "John");
}

TEST_F(ArgumentParserTestGetArgument, GetArgumentNotExists) {
    parser.arguments = { {"name", "John"}, {"age", "25"} };
    std::string result = parser.get_argument("age");
    EXPECT_EQ(result, "25");
}

TEST_F(ArgumentParserTestGetArgument, GetArgumentVerbose) {
    parser.arguments = { {"name", "John"}, {"age", "25"}, {"verbose", "1"} };
    std::string result = parser.get_argument("verbose");
    EXPECT_EQ(result, "1");
}

TEST_F(ArgumentParserTestGetArgument, GetArgumentD) {
    parser.arguments = { {"name", "Amy"}, {"age", "25"}, {"verbose", "1"}, {"d", "1"} };
    std::string result = parser.get_argument("d");
    EXPECT_EQ(result, "1");
}

TEST_F(ArgumentParserTestGetArgument, GetArgumentOption) {
    parser.arguments = { {"name", "John"}, {"age", "25"}, {"verbose", "1"}, {"d", "1"}, {"option", "value"} };
    std::string result = parser.get_argument("option");
    EXPECT_EQ(result, "value");
}

class ArgumentParserTestAddArgument : public ::testing::Test {
protected:
    ArgumentParser parser;

    void SetUp() override {
        
    }
};


TEST_F(ArgumentParserTestAddArgument, AddArgument) {
    parser.add_argument("name");
    parser.add_argument("age", true, "int");

    EXPECT_EQ(parser.required, std::set<std::string>{"age"});
    EXPECT_EQ(parser.types, (std::map<std::string, std::string>{{"name", "string"}, { "age", "int" }}));
}

TEST_F(ArgumentParserTestAddArgument, AddArgumentMultiple) {
    parser.add_argument("name");
    parser.add_argument("age", false, "int");
    parser.add_argument("verbose", false, "bool");

    EXPECT_EQ(parser.required, std::set<std::string>{});
    EXPECT_EQ(parser.types, (std::map<std::string, std::string>{{"name", "string"}, { "age", "int" }, { "verbose", "bool" }}));
}

TEST_F(ArgumentParserTestAddArgument, AddArgumentWithDefault) {
    parser.add_argument("name");
    parser.add_argument("age", false, "int");
    parser.add_argument("verbose", false, "bool");
    parser.add_argument("d");

    EXPECT_EQ(parser.required, std::set<std::string>{});
    EXPECT_EQ(parser.types, (std::map<std::string, std::string>{{"name", "string"}, { "age", "int" }, { "verbose", "bool" }, { "d", "string" }}));
}

class ArgumentParserTestConvertType : public ::testing::Test {
protected:
    ArgumentParser parser;

    void SetUp() override {
        
    }
};


TEST_F(ArgumentParserTestConvertType, ConvertTypeInt) {
    parser.types = { {"age", "int"} };
    std::string result = parser.convert_type("age", "25");
    EXPECT_EQ(result, "25");
}

TEST_F(ArgumentParserTestConvertType, ConvertTypeFail) {
    parser.types = { {"age", "int"} };
    std::string result = parser.convert_type("age", "twenty-five");
    EXPECT_EQ(result, "twenty-five");
}

TEST_F(ArgumentParserTestConvertType, ConvertTypeBoolTrue) {
    parser.types = { {"verbose", "bool"} };
    std::string result = parser.convert_type("verbose", "True");
    EXPECT_EQ(result, "1");
}

TEST_F(ArgumentParserTestConvertType, ConvertTypeBoolFalse) {
    parser.types = { {"verbose", "bool"} };
    std::string result = parser.convert_type("verbose", "False");
    EXPECT_EQ(result, "0");
}

class ArgumentParserTestMain : public ::testing::Test {
protected:
    ArgumentParser parser;

    void SetUp() override {
        
    }
};

TEST_F(ArgumentParserTestMain, ParseArguments) {
    ArgumentParser parser;
    parser.arguments.clear(); 
    std::string command_str = "script --arg1=21 --option1 -arg2 value -option2";

    parser.add_argument("arg1", true, "int");
    parser.add_argument("arg2");
    EXPECT_EQ(parser.required, std::set<std::string>{"arg1"});
    EXPECT_EQ(parser.types, (std::map<std::string, std::string>{{"arg1", "int"}, { "arg2", "string" }}));
    EXPECT_EQ(parser.arguments, (std::map<std::string, std::string>{}));

    auto result_tuple = parser.parse_arguments(command_str);
    bool result = std::get<0>(result_tuple);
    auto arguments = std::get<1>(result_tuple);

    EXPECT_TRUE(result);
    EXPECT_EQ(parser.get_argument("arg1"), "21");
    EXPECT_EQ(parser.get_argument("option1"), "1");
    EXPECT_EQ(parser.get_argument("arg2"), "value");
    EXPECT_EQ(parser.get_argument("option2"), "1");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}