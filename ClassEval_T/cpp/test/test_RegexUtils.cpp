#include <gtest/gtest.h>
#include "pch.h"

class RegexUtilsTest : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTest, TestRegexUtils) {
    
    bool res = ru.match(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-7890");
    EXPECT_TRUE(res);

    
    std::vector<std::string> res_findall = ru.findall(R"(\b\d{3}-\d{3}-\d{4}\b)",
        "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected_findall = { "123-456-7890", "876-286-9876", "987-762-9767" };
    EXPECT_EQ(res_findall, expected_findall);

    
    std::vector<std::string> res_split = ru.split(R"(\b\d{3}-\d{3}-\d{4}\b)",
        "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected_split = { "", " abiguygusu ", " kjgufwycs ", "" };
    EXPECT_EQ(res_split, expected_split);

    
    std::string res_sub = ru.sub(R"(\b\d{3}-\d{3}-\d{4}\b)", "phone num",
        "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::string expected_sub = "phone num abiguygusu phone num kjgufwycs phone num";
    EXPECT_EQ(res_sub, expected_sub);

    
    std::string pat = ru.generate_email_pattern();
    res = ru.match(pat, "iustd87t2euh@163.com");
    EXPECT_TRUE(res);

    
    pat = ru.generate_phone_number_pattern();
    res = ru.match(pat, "123-456-7890");
    EXPECT_TRUE(res);

    
    pat = ru.generate_split_sentences_pattern();
    res = ru.match(pat, "? Y");
    EXPECT_TRUE(res);

    
    std::vector<std::string> res_split_sentences = ru.split_sentences("Aaa. Bbbb? Ccc!");
    std::vector<std::string> expected_split_sentences = { "Aaa", "Bbbb", "Ccc!" };
    EXPECT_EQ(res_split_sentences, expected_split_sentences);

    
    res = ru.validate_phone_number("123-456-7890");
    EXPECT_TRUE(res);

    
    std::vector<std::string> res_extract_email = ru.extract_email("abcdefg@163.com ygusyfysy@126.com wljduyuv@qq.com");
    std::vector<std::string> expected_extract_email = { "abcdefg@163.com", "ygusyfysy@126.com", "wljduyuv@qq.com" };
    EXPECT_EQ(res_extract_email, expected_extract_email);
}

class RegexUtilsTestMatch : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestMatch, test_match_1) {
    bool res = ru.match(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-7890");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestMatch, test_match_2) {
    bool res = ru.match(R"(\b\d{3}-\d{3}-\d{4}\b)", "1234567890");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestMatch, test_match_3) {
    bool res = ru.match(R"(\b\d{3}-\d{3}-\d{4}\b)", "111-111-1111");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestMatch, test_match_4) {
    bool res = ru.match(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-789");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestMatch, test_match_5) {
    bool res = ru.match(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-789a");
    EXPECT_FALSE(res);
}

class RegexUtilsTestFindall : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestFindall, test_findall_1) {
    std::vector<std::string> res = ru.findall(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "123-456-7890", "876-286-9876", "987-762-9767" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestFindall, test_findall_2) {
    std::vector<std::string> res = ru.findall(R"(\b\d{3}-\d{3}-\d{4}\b)", "abiguygusu  kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "987-762-9767" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestFindall, test_findall_3) {
    std::vector<std::string> res = ru.findall(R"(\b\d{3}-\d{3}-\d{4}\b)", "abiguygusu  kjgufwycs ");
    std::vector<std::string> expected = {};
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestFindall, test_findall_4) {
    std::vector<std::string> res = ru.findall(R"(\b\d{3}-\d{3}-\d{4}\b)", "abiguygusu  111-111-1111 kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "111-111-1111", "987-762-9767" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestFindall, test_findall_5) {
    std::vector<std::string> res = ru.findall(R"(\b\d{3}-\d{3}-\d{4}\b)", "abiguygusu  111-111-111a kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "987-762-9767" };
    EXPECT_EQ(res, expected);
}

class RegexUtilsTestSplit : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestSplit, test_split_1) {
    std::vector<std::string> res = ru.split(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "", " abiguygusu ", " kjgufwycs ", "" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplit, test_split_2) {
    std::vector<std::string> res = ru.split(R"(\b\d{3}-\d{3}-\d{4}\b)", "1234567890 abiguygusu 8762869876 kjgufwycs 9877629767");
    std::vector<std::string> expected = { "1234567890 abiguygusu 8762869876 kjgufwycs 9877629767" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplit, test_split_3) {
    std::vector<std::string> res = ru.split(R"(\b\d{3}-\d{3}-\d{4}\b)", "111-111-1111 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "", " abiguygusu ", " kjgufwycs ", "" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplit, test_split_4) {
    std::vector<std::string> res = ru.split(R"(\b\d{3}-\d{3}-\d{4}\b)", "123456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "123456-7890 abiguygusu ", " kjgufwycs ", "" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplit, test_split_5) {
    std::vector<std::string> res = ru.split(R"(\b\d{3}-\d{3}-\d{4}\b)", "123-456-789a abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::vector<std::string> expected = { "123-456-789a abiguygusu ", " kjgufwycs ", "" };
    EXPECT_EQ(res, expected);
}

class RegexUtilsTestSub : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestSub, test_sub_1) {
    std::string res = ru.sub(R"(\b\d{3}-\d{3}-\d{4}\b)", "phone num", "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::string expected = "phone num abiguygusu phone num kjgufwycs phone num";
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSub, test_sub_2) {
    std::string res = ru.sub(R"(\b\d{3}-\d{3}-\d{4}\b)", "phone num", "1234567890 abiguygusu 8762869876 kjgufwycs 9877629767");
    std::string expected = "1234567890 abiguygusu 8762869876 kjgufwycs 9877629767";
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSub, test_sub_3) {
    std::string res = ru.sub(R"(\b\d{3}-\d{3}-\d{4}\b)", "phone num", "123456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::string expected = "123456-7890 abiguygusu phone num kjgufwycs phone num";
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSub, test_sub_4) {
    std::string res = ru.sub(R"(\b\d{3}-\d{3}-\d{4}\b)", "phone num", "123-456-789a abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::string expected = "123-456-789a abiguygusu phone num kjgufwycs phone num";
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSub, test_sub_5) {
    std::string res = ru.sub(R"(\b\d{3}-\d{3}-\d{4}\b)", "phone num", "123-456-780 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
    std::string expected = "123-456-780 abiguygusu phone num kjgufwycs phone num";
    EXPECT_EQ(res, expected);
}

class RegexUtilsTestGenerateEmailPattern : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestGenerateEmailPattern, test_generate_email_pattern_1) {
    std::string pat = ru.generate_email_pattern();
    bool res = ru.match(pat, "iustd87t2euh@163.com");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestGenerateEmailPattern, test_generate_email_pattern_2) {
    std::string pat = ru.generate_email_pattern();
    bool res = ru.match(pat, "iustd87t2euhifg.com");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGenerateEmailPattern, test_generate_email_pattern_3) {
    std::string pat = ru.generate_email_pattern();
    bool res = ru.match(pat, "iustd87t2euhifg@.com");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGenerateEmailPattern, test_generate_email_pattern_4) {
    std::string pat = ru.generate_email_pattern();
    bool res = ru.match(pat, "iustd87t2euhifg@.");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGenerateEmailPattern, test_generate_email_pattern_5) {
    std::string pat = ru.generate_email_pattern();
    bool res = ru.match(pat, "iustd87t2euhifg@com.");
    EXPECT_FALSE(res);
}

class RegexUtilsTestGeneratePhoneNumberPattern : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestGeneratePhoneNumberPattern, test_generate_phone_number_pattern_1) {
    std::string pat = ru.generate_phone_number_pattern();
    bool res = ru.match(pat, "123-456-7890");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestGeneratePhoneNumberPattern, test_generate_phone_number_pattern_2) {
    std::string pat = ru.generate_phone_number_pattern();
    bool res = ru.match(pat, "1234567890");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGeneratePhoneNumberPattern, test_generate_phone_number_pattern_3) {
    std::string pat = ru.generate_phone_number_pattern();
    bool res = ru.match(pat, "123-456-789");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGeneratePhoneNumberPattern, test_generate_phone_number_pattern_4) {
    std::string pat = ru.generate_phone_number_pattern();
    bool res = ru.match(pat, "a23-456-7890");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGeneratePhoneNumberPattern, test_generate_phone_number_pattern_5) {
    std::string pat = ru.generate_phone_number_pattern();
    bool res = ru.match(pat, "1234-56-7890");
    EXPECT_FALSE(res);
}

class RegexUtilsTestGenerateSplitSentencesPattern : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestGenerateSplitSentencesPattern, test_generate_split_sentences_pattern_1) {
    std::string pat = ru.generate_split_sentences_pattern();
    bool res = ru.match(pat, "? Y");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestGenerateSplitSentencesPattern, test_generate_split_sentences_pattern_2) {
    std::string pat = ru.generate_split_sentences_pattern();
    bool res = ru.match(pat, "! Y");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestGenerateSplitSentencesPattern, test_generate_split_sentences_pattern_3) {
    std::string pat = ru.generate_split_sentences_pattern();
    bool res = ru.match(pat, "? ");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGenerateSplitSentencesPattern, test_generate_split_sentences_pattern_4) {
    std::string pat = ru.generate_split_sentences_pattern();
    bool res = ru.match(pat, "?Y");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestGenerateSplitSentencesPattern, test_generate_split_sentences_pattern_5) {
    std::string pat = ru.generate_split_sentences_pattern();
    bool res = ru.match(pat, ".Y");
    EXPECT_FALSE(res);
}

class RegexUtilsTestSplitSentences : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestSplitSentences, test_split_sentences_1) {
    std::vector<std::string> res = ru.split_sentences("Aaa. Bbbb? Ccc!");
    std::vector<std::string> expected = { "Aaa", "Bbbb", "Ccc!" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplitSentences, test_split_sentences_2) {
    std::vector<std::string> res = ru.split_sentences("Aaa.Bbbb? Ccc!");
    std::vector<std::string> expected = { "Aaa.Bbbb", "Ccc!" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplitSentences, test_split_sentences_3) {
    std::vector<std::string> res = ru.split_sentences("Aaa. bbbb? Ccc!");
    std::vector<std::string> expected = { "Aaa. bbbb", "Ccc!" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplitSentences, test_split_sentences_4) {
    std::vector<std::string> res = ru.split_sentences("Aaa. bbbb, Ccc!");
    std::vector<std::string> expected = { "Aaa. bbbb, Ccc!" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestSplitSentences, test_split_sentences_5) {
    std::vector<std::string> res = ru.split_sentences("Aaa, Bbbb? Ccc!");
    std::vector<std::string> expected = { "Aaa, Bbbb", "Ccc!" };
    EXPECT_EQ(res, expected);
}

class RegexUtilsTestValidatePhoneNumber : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestValidatePhoneNumber, test_validate_phone_number_1) {
    bool res = ru.validate_phone_number("123-456-7890");
    EXPECT_TRUE(res);
}

TEST_F(RegexUtilsTestValidatePhoneNumber, test_validate_phone_number_2) {
    bool res = ru.validate_phone_number("1234567890");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestValidatePhoneNumber, test_validate_phone_number_3) {
    bool res = ru.validate_phone_number("a23-456-7890");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestValidatePhoneNumber, test_validate_phone_number_4) {
    bool res = ru.validate_phone_number("123-456-789");
    EXPECT_FALSE(res);
}

TEST_F(RegexUtilsTestValidatePhoneNumber, test_validate_phone_number_5) {
    bool res = ru.validate_phone_number("1234-56-789");
    EXPECT_FALSE(res);
}

class RegexUtilsTestExtractEmail : public ::testing::Test {
protected:
    RegexUtils ru;
};

TEST_F(RegexUtilsTestExtractEmail, test_extract_email_1) {
    std::vector<std::string> res = ru.extract_email("abcdefg@163.com ygusyfysy@126.com wljduyuv@qq.com");
    std::vector<std::string> expected = { "abcdefg@163.com", "ygusyfysy@126.com", "wljduyuv@qq.com" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestExtractEmail, test_extract_email_2) {
    std::vector<std::string> res = ru.extract_email("abcdefg@.com ygusyfysy@126.com wljduyuv@qq.com");
    std::vector<std::string> expected = { "ygusyfysy@126.com", "wljduyuv@qq.com" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestExtractEmail, test_extract_email_3) {
    std::vector<std::string> res = ru.extract_email("abcdefgiscom ygusyfysy@126.com wljduyuv@qq.com");
    std::vector<std::string> expected = { "ygusyfysy@126.com", "wljduyuv@qq.com" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestExtractEmail, test_extract_email_4) {
    std::vector<std::string> res = ru.extract_email("abcdefgiscom ygusyfysy126.com wljduyuv@qq.com");
    std::vector<std::string> expected = { "wljduyuv@qq.com" };
    EXPECT_EQ(res, expected);
}

TEST_F(RegexUtilsTestExtractEmail, test_extract_email_5) {
    std::vector<std::string> res = ru.extract_email("abcdefgiscom ygusyfysy@.com wljduyuv@qq.com");
    std::vector<std::string> expected = { "wljduyuv@qq.com" };
    EXPECT_EQ(res, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}