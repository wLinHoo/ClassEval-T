#include <gtest/gtest.h>
#include <string>
#include <map>
#include <vector>
#include <variant>
#include "pch.h"

class HotelTestBookRoom : public ::testing::Test {
protected:
    Hotel* hotel;

    void SetUp() override {
        hotel = new Hotel("peace hotel", { {"single", 3}, {"double", 2} });
    }

    void TearDown() override {
        delete hotel;
    }
};

TEST_F(HotelTestBookRoom, test_book_room_1) {
    auto result = hotel->book_room("single", 2, "guest 1");
    EXPECT_EQ(result, "Success!");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", {{"guest 1", 2}}} };
    EXPECT_EQ(hotel->booked_rooms, now);
    std::unordered_map<std::string, int> kkk{ {"single", 1}, {"double", 2} };
    EXPECT_EQ(hotel->available_rooms, kkk);
}

TEST_F(HotelTestBookRoom, test_book_room_2) {
    auto result = hotel->book_room("triple", 2, "guest 1");
    EXPECT_EQ(result, "False.");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{};
    EXPECT_EQ(hotel->booked_rooms, now);
    std::unordered_map<std::string, int> kkk{ {"single", 3}, { "double", 2 } };
    EXPECT_EQ(hotel->available_rooms, kkk);
}

TEST_F(HotelTestBookRoom, test_book_room_3) {
    hotel->book_room("single", 2, "guest 1");
    auto result = hotel->book_room("single", 2, "guest 2");
    EXPECT_EQ(result, "1");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 2} }} };
    EXPECT_EQ(hotel->booked_rooms, now);
    std::unordered_map<std::string, int> kkk{ {"single", 1}, { "double", 2 } };
    EXPECT_EQ(hotel->available_rooms, kkk);
}

TEST_F(HotelTestBookRoom, test_book_room_4) {
    hotel->book_room("single", 2, "guest 1");
    auto result = hotel->book_room("single", 1, "guest 2");
    EXPECT_EQ(result, "Success!");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 2}, {"guest 2", 1} }} };
    EXPECT_EQ(hotel->booked_rooms, now);
    std::unordered_map<std::string, int> kkk{ {"double", 2}, { "single", 0 } };
    EXPECT_EQ(hotel->available_rooms, kkk);
}

TEST_F(HotelTestBookRoom, test_book_room_5) {
    hotel->book_room("single", 2, "guest 1");
    auto result = hotel->book_room("single", 3, "guest 2");
    EXPECT_EQ(result, "1");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 2} }} };
    EXPECT_EQ(hotel->booked_rooms, now);
    std::unordered_map<std::string, int> kkk{ {"single", 1}, { "double", 2 } };
    EXPECT_EQ(hotel->available_rooms, kkk);
}

TEST_F(HotelTestBookRoom, test_book_room_6) {
    hotel->book_room("single", 3, "guest 1");
    auto result = hotel->book_room("single", 100, "guest 1");
    EXPECT_EQ(result,"False.");
}

class HotelTestCheckIn : public ::testing::Test {
protected:
    Hotel* hotel;

    void SetUp() override {
        hotel = new Hotel("Test Hotel", { {"single", 3}, {"double", 2} });
        hotel->booked_rooms = { {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    }

    void TearDown() override {
        delete hotel;
    }
};

TEST_F(HotelTestCheckIn, test_check_in_1) {
    hotel->check_in("single", 1, "guest 1");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 1} }}, { "double", {{"guest 2", 1}} } };
    EXPECT_EQ(hotel->booked_rooms, now);
}

TEST_F(HotelTestCheckIn, test_check_in_2) {
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 2} }}, { "double", {{"guest 2", 1}} } };
    EXPECT_FALSE(hotel->check_in("single", 3, "guest 1"));
    EXPECT_EQ(hotel->booked_rooms, now);
}

TEST_F(HotelTestCheckIn, test_check_in_3) {
    EXPECT_FALSE(hotel->check_in("double", 1, "guest 1"));
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 2} }}, { "double", {{"guest 2", 1}} } };
    EXPECT_EQ(hotel->booked_rooms, now);
}

TEST_F(HotelTestCheckIn, test_check_in_4) {
    hotel->check_in("double", 1, "guest 2");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"double", {}}, { "single", {{"guest 1", 2}} } };
    EXPECT_EQ(hotel->booked_rooms, now);
}

TEST_F(HotelTestCheckIn, test_check_in_5) {
    hotel->check_in("double", 2, "guest 2");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"double", { {"guest 2", 1} }}, { "single", {{"guest 1", 2}} } };
    EXPECT_EQ(hotel->booked_rooms, now);
}

TEST_F(HotelTestCheckIn, test_check_in_6) {
    auto res = hotel->check_in("abc", 1, "guest 1");
    EXPECT_FALSE(res);
}

class HotelTestCheckOut : public ::testing::Test {
protected:
    Hotel* hotel;

    void SetUp() override {
        hotel = new Hotel("Test Hotel", { {"single", 3}, {"double", 2} });
        hotel->booked_rooms = { {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    }

    void TearDown() override {
        delete hotel;
    }
};

TEST_F(HotelTestCheckOut, test_check_out_1) {
    hotel->check_out("single", 1);
    std::unordered_map<std::string, int> now{ {"single", 4}, { "double", 2 } };
    EXPECT_EQ(hotel->available_rooms, now);
    std::unordered_map<std::string, std::unordered_map<std::string, int>> kkk{ {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    EXPECT_EQ(hotel->booked_rooms, kkk);
}

TEST_F(HotelTestCheckOut, test_check_out_2) {
    hotel->check_out("single", 3);
    std::unordered_map<std::string, int> now{ {"single", 6}, { "double", 2 } };
    EXPECT_EQ(hotel->available_rooms, now);
    std::unordered_map<std::string, std::unordered_map<std::string, int>> kkk{ {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    EXPECT_EQ(hotel->booked_rooms, kkk);
}

TEST_F(HotelTestCheckOut, test_check_out_3) {
    hotel->check_out("triple", 2);
    std::unordered_map<std::string, int> now{ {"single", 3}, { "double", 2 }, { "triple", 2 } };
    EXPECT_EQ(hotel->available_rooms, now);
    std::unordered_map<std::string, std::unordered_map<std::string, int>> kkk{ {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    EXPECT_EQ(hotel->booked_rooms, kkk);
}

TEST_F(HotelTestCheckOut, test_check_out_4) {
    hotel->check_out("double", 1);
    std::unordered_map<std::string, int> now{ {"single", 3}, { "double", 3 } };
    EXPECT_EQ(hotel->available_rooms, now);
    std::unordered_map<std::string, std::unordered_map<std::string, int>> kkk{ {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    EXPECT_EQ(hotel->booked_rooms, kkk);
}

TEST_F(HotelTestCheckOut, test_check_out_5) {
    hotel->check_out("double", 2);
    std::unordered_map<std::string, int> now{ {"single", 3}, { "double", 4 } };
    EXPECT_EQ(hotel->available_rooms, now);
    std::unordered_map<std::string, std::unordered_map<std::string, int>> kkk{ {"single", {{"guest 1", 2}}}, {"double", {{"guest 2", 1}}} };
    EXPECT_EQ(hotel->booked_rooms, kkk);
}

class HotelTestAvailableRooms : public ::testing::Test {
protected:
    void SetUp() override {
        hotel = new Hotel("Test Hotel", { {"single", 3}, {"double", 2}, {"triple", 2} });
    }

    void TearDown() override {
        delete hotel;
    }

    Hotel* hotel;
};

TEST_F(HotelTestAvailableRooms, test_get_available_rooms) {
    int result = hotel->get_available_rooms("single");
    EXPECT_EQ(result, 3);
}

TEST_F(HotelTestAvailableRooms, test_get_available_rooms_2) {
    hotel->book_room("single", 2, "guest 1");
    int result = hotel->get_available_rooms("single");
    EXPECT_EQ(result, 1);
}

TEST_F(HotelTestAvailableRooms, test_get_available_rooms_3) {
    hotel->book_room("single", 3, "guest 1");
    int result = hotel->get_available_rooms("single");
    EXPECT_EQ(result, 0);
}

TEST_F(HotelTestAvailableRooms, test_get_available_rooms_4) {
    hotel->book_room("single", 3, "guest 1");
    int result = hotel->get_available_rooms("double");
    EXPECT_EQ(result, 2);
}

TEST_F(HotelTestAvailableRooms, test_get_available_rooms_5) {
    hotel->book_room("single", 3, "guest 1");
    int result = hotel->get_available_rooms("triple");
    EXPECT_EQ(result, 2);
}

class HotelTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        hotel = new Hotel("Test Hotel", { {"single", 3}, {"double", 2} });
    }

    void TearDown() override {
        delete hotel;
    }

    Hotel* hotel;
};

TEST_F(HotelTestMain, test_main) {
    std::string result = hotel->book_room("single", 2, "guest 1");
    EXPECT_EQ(result, "Success!");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> now{ {"single", { {"guest 1", 2} }} };
    EXPECT_EQ(hotel->booked_rooms, now);
    EXPECT_EQ(hotel->available_rooms, (std::unordered_map<std::string, int>{{"single", 1}, { "double", 2 }}));

    hotel->check_in("single", 2, "guest 1");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> kkk{ {"single", {}} };
    EXPECT_EQ(hotel->booked_rooms, kkk);
    EXPECT_EQ(hotel->available_rooms, (std::unordered_map<std::string, int>{{"single", 1}, { "double", 2 }}));

    hotel->check_out("single", 2);
    EXPECT_EQ(hotel->available_rooms, (std::unordered_map<std::string, int>{{"single", 3}, { "double", 2 }}));

    EXPECT_EQ(hotel->get_available_rooms("single"), 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}