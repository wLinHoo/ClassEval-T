#include <gtest/gtest.h>
#include "pch.h"

class TimeUtilsTest : public ::testing::Test
{
};

TEST_F(TimeUtilsTest, TestTimeUtils)
{
    TimeUtils timeutils;

    std::stringstream ss;

    ss << std::put_time(&timeutils.datetime, "%H:%M:%S");
    EXPECT_EQ(timeutils.get_current_time(), ss.str());

    ss.str("");
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d");
    EXPECT_EQ(timeutils.get_current_date(), ss.str());

    ss.str("");
    std::string added_time = timeutils.add_seconds(600);
    ss << std::put_time(&(timeutils.datetime), "%H:%M:%S");
    EXPECT_EQ(added_time, ss.str());

    std::tm expected_tm = {};
    std::istringstream input("2001-07-18 01:01:01");
    input >> std::get_time(&expected_tm, "%Y-%m-%d %H:%M:%S");
    std::tm now_tm = timeutils.string_to_datetime("2001-07-18 01:01:01");
    EXPECT_EQ(std::mktime(&expected_tm), std::mktime(&now_tm));

    ss.str("");
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d %H:%M:%S");
    EXPECT_EQ(timeutils.datetime_to_string(timeutils.datetime), ss.str());

    EXPECT_EQ(timeutils.get_minutes("2001-07-18 01:01:01", "2001-07-18 02:01:01"), 60);

    EXPECT_EQ(timeutils.get_format_time(2001, 7, 18, 1, 1, 1), "2001-07-18 01:01:01");
}

class TimeUtilsTestGetCurrentTime : public ::testing::Test
{
};

TEST_F(TimeUtilsTestGetCurrentTime, test_get_current_time_1)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%H:%M:%S");
    EXPECT_EQ(timeutils.get_current_time(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentTime, test_get_current_time_2)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%H:%M:%S");
    EXPECT_EQ(timeutils.get_current_time(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentTime, test_get_current_time_3)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%H:%M:%S");
    EXPECT_EQ(timeutils.get_current_time(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentTime, test_get_current_time_4)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%H:%M:%S");
    EXPECT_EQ(timeutils.get_current_time(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentTime, test_get_current_time_5)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%H:%M:%S");
    EXPECT_EQ(timeutils.get_current_time(), ss.str());
}

class TimeUtilsTestGetCurrentDate : public ::testing::Test
{
};

TEST_F(TimeUtilsTestGetCurrentDate, test_get_current_date_1)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d");
    EXPECT_EQ(timeutils.get_current_date(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentDate, test_get_current_date_2)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d");
    EXPECT_EQ(timeutils.get_current_date(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentDate, test_get_current_date_3)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d");
    EXPECT_EQ(timeutils.get_current_date(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentDate, test_get_current_date_4)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d");
    EXPECT_EQ(timeutils.get_current_date(), ss.str());
}

TEST_F(TimeUtilsTestGetCurrentDate, test_get_current_date_5)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d");
    EXPECT_EQ(timeutils.get_current_date(), ss.str());
}

class TimeUtilsTestAddSeconds : public ::testing::Test
{
};

TEST_F(TimeUtilsTestAddSeconds, test_add_seconds_1)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::string added_time = timeutils.add_seconds(600);
    ss << std::put_time(&(timeutils.datetime), "%H:%M:%S");
    EXPECT_EQ(added_time, ss.str());
}

TEST_F(TimeUtilsTestAddSeconds, test_add_seconds_2)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::string added_time = timeutils.add_seconds(500);
    ss << std::put_time(&(timeutils.datetime), "%H:%M:%S");
    EXPECT_EQ(added_time, ss.str());
}

TEST_F(TimeUtilsTestAddSeconds, test_add_seconds_3)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::string added_time = timeutils.add_seconds(400);
    ss << std::put_time(&(timeutils.datetime), "%H:%M:%S");
    EXPECT_EQ(added_time, ss.str());
}

TEST_F(TimeUtilsTestAddSeconds, test_add_seconds_4)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::string added_time = timeutils.add_seconds(300);
    ss << std::put_time(&(timeutils.datetime), "%H:%M:%S");
    EXPECT_EQ(added_time, ss.str());
}

TEST_F(TimeUtilsTestAddSeconds, test_add_seconds_5)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::string added_time = timeutils.add_seconds(200);
    ss << std::put_time(&(timeutils.datetime), "%H:%M:%S");
    EXPECT_EQ(added_time, ss.str());
}

class TimeUtilsTestStringToDatetime : public ::testing::Test
{
};

TEST_F(TimeUtilsTestStringToDatetime, test_string_to_datetime_1)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::tm expected_tm = {};
    std::istringstream input("2001-07-18 01:01:01");
    input >> std::get_time(&expected_tm, "%Y-%m-%d %H:%M:%S");
    std::tm now_tm = timeutils.string_to_datetime("2001-07-18 01:01:01");
    EXPECT_EQ(std::mktime(&expected_tm), std::mktime(&now_tm));
}

TEST_F(TimeUtilsTestStringToDatetime, test_string_to_datetime_2)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::tm expected_tm = {};
    std::istringstream input("2001-07-17 01:01:01");
    input >> std::get_time(&expected_tm, "%Y-%m-%d %H:%M:%S");
    std::tm now_tm = timeutils.string_to_datetime("2001-07-17 01:01:01");
    EXPECT_EQ(std::mktime(&expected_tm), std::mktime(&now_tm));
}

TEST_F(TimeUtilsTestStringToDatetime, test_string_to_datetime_3)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::tm expected_tm = {};
    std::istringstream input("2001-07-16 01:01:01");
    input >> std::get_time(&expected_tm, "%Y-%m-%d %H:%M:%S");
    std::tm now_tm = timeutils.string_to_datetime("2001-07-16 01:01:01");
    EXPECT_EQ(std::mktime(&expected_tm), std::mktime(&now_tm));
}

TEST_F(TimeUtilsTestStringToDatetime, test_string_to_datetime_4)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::tm expected_tm = {};
    std::istringstream input("2001-07-15 01:01:01");
    input >> std::get_time(&expected_tm, "%Y-%m-%d %H:%M:%S");
    std::tm now_tm = timeutils.string_to_datetime("2001-07-15 01:01:01");
    EXPECT_EQ(std::mktime(&expected_tm), std::mktime(&now_tm));
}

TEST_F(TimeUtilsTestStringToDatetime, test_string_to_datetime_5)
{
    TimeUtils timeutils;
    std::stringstream ss;
    std::tm expected_tm = {};
    std::istringstream input("2001-07-14 01:01:01");
    input >> std::get_time(&expected_tm, "%Y-%m-%d %H:%M:%S");
    std::tm now_tm = timeutils.string_to_datetime("2001-07-14 01:01:01");
    EXPECT_EQ(std::mktime(&expected_tm), std::mktime(&now_tm));
}

class TimeUtilsTestDatetimeToString : public ::testing::Test
{
};

TEST_F(TimeUtilsTestDatetimeToString, test_datetime_to_string_1)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d %H:%M:%S");
    EXPECT_EQ(timeutils.datetime_to_string(timeutils.datetime), ss.str());
}

TEST_F(TimeUtilsTestDatetimeToString, test_datetime_to_string_2)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d %H:%M:%S");
    EXPECT_EQ(timeutils.datetime_to_string(timeutils.datetime), ss.str());
}

TEST_F(TimeUtilsTestDatetimeToString, test_datetime_to_string_3)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d %H:%M:%S");
    EXPECT_EQ(timeutils.datetime_to_string(timeutils.datetime), ss.str());
}

TEST_F(TimeUtilsTestDatetimeToString, test_datetime_to_string_4)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d %H:%M:%S");
    EXPECT_EQ(timeutils.datetime_to_string(timeutils.datetime), ss.str());
}

TEST_F(TimeUtilsTestDatetimeToString, test_datetime_to_string_5)
{
    TimeUtils timeutils;
    std::stringstream ss;
    ss << std::put_time(&timeutils.datetime, "%Y-%m-%d %H:%M:%S");
    EXPECT_EQ(timeutils.datetime_to_string(timeutils.datetime), ss.str());
}

class TimeUtilsTestGetMinutes : public ::testing::Test
{
};

TEST_F(TimeUtilsTestGetMinutes, test_get_minutes_1)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_minutes("2001-07-18 01:01:01", "2001-07-18 02:01:01"), 60);
}

TEST_F(TimeUtilsTestGetMinutes, test_get_minutes_2)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_minutes("2001-07-18 01:01:01", "2001-07-18 03:01:01"), 120);
}

TEST_F(TimeUtilsTestGetMinutes, test_get_minutes_3)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_minutes("2001-07-18 01:01:01", "2001-07-18 04:01:01"), 180);
}

TEST_F(TimeUtilsTestGetMinutes, test_get_minutes_4)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_minutes("2001-07-18 01:01:01", "2001-07-18 05:01:01"), 240);
}

TEST_F(TimeUtilsTestGetMinutes, test_get_minutes_5)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_minutes("2001-07-18 01:01:01", "2001-07-18 06:01:01"), 300);
}

class TimeUtilsTestGetFormatTime : public ::testing::Test
{
};

TEST_F(TimeUtilsTestGetFormatTime, test_get_format_time_1)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_format_time(2001, 7, 18, 1, 1, 1), "2001-07-18 01:01:01");
}

TEST_F(TimeUtilsTestGetFormatTime, test_get_format_time_2)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_format_time(2001, 7, 17, 1, 1, 1), "2001-07-17 01:01:01");
}

TEST_F(TimeUtilsTestGetFormatTime, test_get_format_time_3)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_format_time(2001, 7, 16, 1, 1, 1), "2001-07-16 01:01:01");
}

TEST_F(TimeUtilsTestGetFormatTime, test_get_format_time_4)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_format_time(2001, 7, 15, 1, 1, 1), "2001-07-15 01:01:01");
}

TEST_F(TimeUtilsTestGetFormatTime, test_get_format_time_5)
{
    TimeUtils timeutils;
    EXPECT_EQ(timeutils.get_format_time(2001, 7, 14, 1, 1, 1), "2001-07-14 01:01:01");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}