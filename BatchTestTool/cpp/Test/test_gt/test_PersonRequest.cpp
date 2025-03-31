#include <gtest/gtest.h>
#include "pch.h"

class PersonRequestTestValidateName :public::testing::Test {};

TEST(PersonRequestTestValidateName, ValidateName1) {
	PersonRequest pr("", "Man", "12345678901");
	EXPECT_EQ(pr.name, "");
}

TEST(PersonRequestTestValidateName, ValidateName2) {
	PersonRequest pr("This is a very long name that exceeds the character limit", "Man", "12345678901");
	EXPECT_EQ(pr.name, "");
}

TEST(PersonRequestTestValidateName, ValidateName3) {
	PersonRequest pr("aaa", "Man", "12345678901");
	EXPECT_EQ(pr.name, "aaa");
}

TEST(PersonRequestTestValidateName, ValidateName4) {
	PersonRequest pr("bbb", "Man", "12345678901");
	EXPECT_EQ(pr.name, "bbb");
}

TEST(PersonRequestTestValidateName, ValidateName5) {
	PersonRequest pr("ccc", "Man", "12345678901");
	EXPECT_EQ(pr.name, "ccc");
}

class PersonRequestTestValidateSex :public::testing::Test {};

TEST(PersonRequestTestValidateSex, ValidateSex1) {
	PersonRequest pr("John Doe", "Unknown", "12345678901");
	EXPECT_EQ(pr.sex, "");
}

TEST(PersonRequestTestValidateSex, ValidateSex2) {
	PersonRequest pr("John Doe", "UGM", "12345678901");
	EXPECT_EQ(pr.sex, "UGM");
}

TEST(PersonRequestTestValidateSex, ValidateSex3) {
	PersonRequest pr("John Doe", "Man", "12345678901");
	EXPECT_EQ(pr.sex, "Man");
}

TEST(PersonRequestTestValidateSex, ValidateSex4) {
	PersonRequest pr("John Doe", "Woman", "12345678901");
	EXPECT_EQ(pr.sex, "Woman");
}

TEST(PersonRequestTestValidateSex, ValidateSex5) {
	PersonRequest pr("John Doe", "khsigy", "12345678901");
	EXPECT_EQ(pr.sex, "");
}

class PersonRequestTestValidatePhoneNumber :public::testing::Test {};

TEST(PersonRequestTestValidatePhoneNumber, ValidatePhoneNumber1) {
	PersonRequest pr("John Doe", "Man", "");
	EXPECT_EQ(pr.phoneNumber, "");
}

TEST(PersonRequestTestValidatePhoneNumber, ValidatePhoneNumber2) {
	PersonRequest pr("John Doe", "Man", "12345");
	EXPECT_EQ(pr.phoneNumber, "");
}

TEST(PersonRequestTestValidatePhoneNumber, ValidatePhoneNumber3) {
	PersonRequest pr("John Doe", "Man", "jgdjrj");
	EXPECT_EQ(pr.phoneNumber, "");
}

TEST(PersonRequestTestValidatePhoneNumber, ValidatePhoneNumber4) {
	PersonRequest pr("John Doe", "Man", "12345678901");
	EXPECT_EQ(pr.phoneNumber, "12345678901");
}

TEST(PersonRequestTestValidatePhoneNumber, ValidatePhoneNumber5) {
	PersonRequest pr("John Doe", "Man", "11111111111");
	EXPECT_EQ(pr.phoneNumber, "11111111111");
}

class PersonRequestTest :public::testing::Test {};

TEST(PersonRequestTest, PersonRequestTest) {
	PersonRequest pr("", "Man", "12345678901");
	EXPECT_EQ(pr.name, "");

	pr = PersonRequest("John Doe", "Unknown", "12345678901");
	EXPECT_EQ(pr.sex, "");

	pr = PersonRequest("John Doe", "Man", "");
	EXPECT_EQ(pr.phoneNumber, "");
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
