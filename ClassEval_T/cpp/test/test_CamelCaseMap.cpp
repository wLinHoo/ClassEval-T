#include "gtest/gtest.h"
#include "pch.h"


class CamelCaseMapTestGetitem : public ::testing::Test
{
};

TEST_F(CamelCaseMapTestGetitem, test_getitem_1)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    EXPECT_EQ(camelize_map.get_item("first_name"), "John");
}

TEST_F(CamelCaseMapTestGetitem, test_getitem_2)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("last_name", "Doe");
    EXPECT_EQ(camelize_map.get_item("last_name"), "Doe");
}

TEST_F(CamelCaseMapTestGetitem, test_getitem_3)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("age", "30");
    EXPECT_EQ(camelize_map.get_item("age"), "30");
}

TEST_F(CamelCaseMapTestGetitem, test_getitem_4)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    EXPECT_EQ(camelize_map.get_item("first_Name"), "John");
}

TEST_F(CamelCaseMapTestGetitem, test_getitem_5)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    EXPECT_EQ(camelize_map.get_item("firstName"), "John");
}


class CamelCaseMapTestSetitem : public ::testing::Test
{
};

TEST_F(CamelCaseMapTestSetitem, test_setitem_1)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("first_name", "newname");
    EXPECT_EQ(camelize_map.get_item("first_name"), "newname");
}

TEST_F(CamelCaseMapTestSetitem, test_setitem_2)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("first_name", "John");
    EXPECT_EQ(camelize_map.get_item("first_name"), "John");
}

TEST_F(CamelCaseMapTestSetitem, test_setitem_3)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("first_Name", "newname");
    EXPECT_EQ(camelize_map.get_item("first_name"), "newname");
}

TEST_F(CamelCaseMapTestSetitem, test_setitem_4)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("firstName", "newname");
    EXPECT_EQ(camelize_map.get_item("first_name"), "newname");
}

TEST_F(CamelCaseMapTestSetitem, test_setitem_5)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("first_name", "");
    EXPECT_EQ(camelize_map.get_item("first_name"), "");
}


class CamelCaseMapTestDelitem : public ::testing::Test
{
};

TEST_F(CamelCaseMapTestDelitem, test_delitem_1)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("last_name", "Doe");
    camelize_map.del_item("first_name");
    EXPECT_EQ(camelize_map.get_item("last_name"), "Doe");
}

TEST_F(CamelCaseMapTestDelitem, test_delitem_2)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.del_item("first_name");
    EXPECT_THROW(camelize_map.get_item("first_name"), std::out_of_range);
}

TEST_F(CamelCaseMapTestDelitem, test_delitem_3)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.del_item("first_Name");
    EXPECT_THROW(camelize_map.get_item("first_name"), std::out_of_range);
}

TEST_F(CamelCaseMapTestDelitem, test_delitem_4)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.del_item("firstName");
    EXPECT_THROW(camelize_map.get_item("first_name"), std::out_of_range);
}

TEST_F(CamelCaseMapTestDelitem, test_delitem_5)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "");
    camelize_map.del_item("first_name");
    EXPECT_THROW(camelize_map.get_item("first_name"), std::out_of_range);
}


class CamelCaseMapTestIter : public ::testing::Test
{
};
TEST_F(CamelCaseMapTestIter, test_iter_1)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("last_name", "Doe");
    camelize_map.set_item("age", "30");
    std::vector<std::string> expected = {"firstName", "lastName", "age"};

    auto iter = camelize_map.begin();
    int i = 0;
    while (iter != camelize_map.end())
    {
        EXPECT_EQ(*iter, expected[i]);
        ++iter;
        ++i;
    }
}

TEST_F(CamelCaseMapTestIter, test_iter_2)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("firstname", "John");
    camelize_map.set_item("lastname", "Doe");
    camelize_map.set_item("age", "30");
    std::vector<std::string> expected = {"firstname", "lastname", "age"};

    auto iter = camelize_map.begin();
    int i = 0;
    while (iter != camelize_map.end())
    {
        EXPECT_EQ(*iter, expected[i]);
        ++iter;
        ++i;
    }
}

TEST_F(CamelCaseMapTestIter, test_iter_3)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_Name", "John");
    camelize_map.set_item("last_Name", "Doe");
    camelize_map.set_item("age", "30");
    std::vector<std::string> expected = {"firstName", "lastName", "age"};

    auto iter = camelize_map.begin();
    int i = 0;
    while (iter != camelize_map.end())
    {
        EXPECT_EQ(*iter, expected[i]);
        ++iter;
        ++i;
    }
}

TEST_F(CamelCaseMapTestIter, test_iter_4)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_Name", "John");
    camelize_map.set_item("last_Name", "Doe");
    std::vector<std::string> expected = {"firstName", "lastName"};

    auto iter = camelize_map.begin();
    int i = 0;
    while (iter != camelize_map.end())
    {
        EXPECT_EQ(*iter, expected[i]);
        ++iter;
        ++i;
    }
}

TEST_F(CamelCaseMapTestIter, test_iter_5)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_Name", "John");
    std::vector<std::string> expected = {"firstName"};

    auto iter = camelize_map.begin();
    int i = 0;
    while (iter != camelize_map.end())
    {
        EXPECT_EQ(*iter, expected[i]);
        ++iter;
        ++i;
    }
}


class CamelCaseMapTestLen : public ::testing::Test
{
};
TEST_F(CamelCaseMapTestLen, test_len_1)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    EXPECT_EQ(camelize_map.len(), 1);
}

TEST_F(CamelCaseMapTestLen, test_len_2)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("last_name", "Doe");
    EXPECT_EQ(camelize_map.len(), 1);
}

TEST_F(CamelCaseMapTestLen, test_len_3)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("age", "30");
    EXPECT_EQ(camelize_map.len(), 1);
}

TEST_F(CamelCaseMapTestLen, test_len_4)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    camelize_map.set_item("last_Name", "Doe");
    camelize_map.set_item("age", "30");
    EXPECT_EQ(camelize_map.len(), 3);
}

TEST_F(CamelCaseMapTestLen, test_len_5)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.len(), 0);
}


class CamelCaseMapTestConvertKey : public ::testing::Test
{
};
TEST_F(CamelCaseMapTestConvertKey, test_convert_key_1)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.convert_key("aaa_bbb"), "aaaBbb");
}

TEST_F(CamelCaseMapTestConvertKey, test_convert_key_2)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.convert_key("first_name"), "firstName");
}

TEST_F(CamelCaseMapTestConvertKey, test_convert_key_3)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.convert_key("last_name"), "lastName");
}

TEST_F(CamelCaseMapTestConvertKey, test_convert_key_4)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.convert_key("ccc_ddd"), "cccDdd");
}

TEST_F(CamelCaseMapTestConvertKey, test_convert_key_5)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.convert_key("eee_fff"), "eeeFff");
}

TEST_F(CamelCaseMapTestConvertKey, test_convert_key_6)
{
    CamelCaseMap camelize_map;
    EXPECT_EQ(camelize_map.convert_key(std::to_string(1234)), "1234");
}


class CamelCaseMapTestToCamelCase : public ::testing::Test
{
};
TEST_F(CamelCaseMapTestToCamelCase, test_to_camel_case_1)
{
    EXPECT_EQ(CamelCaseMap::to_camel_case("aaa_bbb"), "aaaBbb");
}

TEST_F(CamelCaseMapTestToCamelCase, test_to_camel_case_2)
{
    EXPECT_EQ(CamelCaseMap::to_camel_case("first_name"), "firstName");
}

TEST_F(CamelCaseMapTestToCamelCase, test_to_camel_case_3)
{
    EXPECT_EQ(CamelCaseMap::to_camel_case("last_name"), "lastName");
}

TEST_F(CamelCaseMapTestToCamelCase, test_to_camel_case_4)
{
    EXPECT_EQ(CamelCaseMap::to_camel_case("ccc_ddd"), "cccDdd");
}

TEST_F(CamelCaseMapTestToCamelCase, test_to_camel_case_5)
{
    EXPECT_EQ(CamelCaseMap::to_camel_case("eee_fff"), "eeeFff");
}


class CamelCaseMapTest : public ::testing::Test
{
};
TEST_F(CamelCaseMapTest, test_CamelCaseMap)
{
    CamelCaseMap camelize_map;
    camelize_map.set_item("first_name", "John");
    EXPECT_EQ(camelize_map.get_item("first_name"), "John");

    CamelCaseMap camelize_map2;
    camelize_map2.set_item("first_name", "John");
    camelize_map2.set_item("first_name", "newname");
    EXPECT_EQ(camelize_map2.get_item("first_name"), "newname");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}