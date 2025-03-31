#include "pch.h"
#include <gtest/gtest.h>

class MovieBookingSystemTestAddMovie : public ::testing::Test {
protected:
    MovieBookingSystem* system;

    void SetUp() override {
        system = new MovieBookingSystem();
    }

    void TearDown() override {
        delete system;
    }
};

TEST_F(MovieBookingSystemTestAddMovie, test_add_movie_1) {
    system->add_movie("Batman", 49.9, "17:05", "19:25", 3);
    ASSERT_EQ(system->movies.size(), 1);
    EXPECT_EQ(system->movies[0].name, "Batman");
    EXPECT_EQ(system->movies[0].price, 49.9);
    EXPECT_EQ(system->movies[0].start_time.tm_hour, 17);
    EXPECT_EQ(system->movies[0].start_time.tm_min, 5);
    EXPECT_EQ(system->movies[0].end_time.tm_hour, 19);
    EXPECT_EQ(system->movies[0].end_time.tm_min, 25);
    EXPECT_EQ(system->movies[0].seats.size(), 3);
    EXPECT_EQ(system->movies[0].seats[0].size(), 3);
}

TEST_F(MovieBookingSystemTestAddMovie, test_add_movie_2) {
    system->add_movie("Batman", 49.9, "17:05", "19:25", 3);
    system->add_movie("Superman", 49.9, "17:05", "19:25", 3);
    ASSERT_EQ(system->movies.size(), 2);
    EXPECT_EQ(system->movies[0].name, "Batman");
    EXPECT_EQ(system->movies[1].name, "Superman");
}

TEST_F(MovieBookingSystemTestAddMovie, test_add_movie_3) {
    system->add_movie("Batman", 39.9, "17:05", "19:25", 3);
    ASSERT_EQ(system->movies.size(), 1);
    EXPECT_EQ(system->movies[0].name, "Batman");
    EXPECT_EQ(system->movies[0].price, 39.9);
    EXPECT_EQ(system->movies[0].start_time.tm_hour, 17);
    EXPECT_EQ(system->movies[0].start_time.tm_min, 5);
    EXPECT_EQ(system->movies[0].end_time.tm_hour, 19);
    EXPECT_EQ(system->movies[0].end_time.tm_min, 25);
    EXPECT_EQ(system->movies[0].seats.size(), 3);
    EXPECT_EQ(system->movies[0].seats[0].size(), 3);
}

TEST_F(MovieBookingSystemTestAddMovie, test_add_movie_4) {
    system->add_movie("Batman", 29.9, "17:05", "19:25", 3);
    ASSERT_EQ(system->movies.size(), 1);
    EXPECT_EQ(system->movies[0].name, "Batman");
    EXPECT_EQ(system->movies[0].price, 29.9);
    EXPECT_EQ(system->movies[0].start_time.tm_hour, 17);
    EXPECT_EQ(system->movies[0].start_time.tm_min, 5);
    EXPECT_EQ(system->movies[0].end_time.tm_hour, 19);
    EXPECT_EQ(system->movies[0].end_time.tm_min, 25);
    EXPECT_EQ(system->movies[0].seats.size(), 3);
    EXPECT_EQ(system->movies[0].seats[0].size(), 3);
}

TEST_F(MovieBookingSystemTestAddMovie, test_add_movie_5) {
    system->add_movie("Batman", 19.9, "17:05", "19:25", 3);
    ASSERT_EQ(system->movies.size(), 1);
    EXPECT_EQ(system->movies[0].name, "Batman");
    EXPECT_EQ(system->movies[0].price, 19.9);
    EXPECT_EQ(system->movies[0].start_time.tm_hour, 17);
    EXPECT_EQ(system->movies[0].start_time.tm_min, 5);
    EXPECT_EQ(system->movies[0].end_time.tm_hour, 19);
    EXPECT_EQ(system->movies[0].end_time.tm_min, 25);
    EXPECT_EQ(system->movies[0].seats.size(), 3);
    EXPECT_EQ(system->movies[0].seats[0].size(), 3);
}

class MovieBookingSystemTestBookTicket : public ::testing::Test {
protected:
    MovieBookingSystem* system;

    void SetUp() override {
        system = new MovieBookingSystem();
        system->add_movie("Batman", 49.9, "17:05", "19:25", 3);
    }

    void TearDown() override {
        delete system;
    }
};

TEST_F(MovieBookingSystemTestBookTicket, test_book_ticket_1) {
    std::vector<std::pair<int, int>> seats_to_book = { {0, 0}, {1, 1}, {2, 2} };
    std::string result = system->book_ticket("Batman", seats_to_book);
    EXPECT_EQ(result, "Booking success.");
    EXPECT_EQ(system->movies[0].seats[0][0], 1);
    EXPECT_EQ(system->movies[0].seats[1][1], 1);
    EXPECT_EQ(system->movies[0].seats[2][2], 1);
}

TEST_F(MovieBookingSystemTestBookTicket, test_book_ticket_2) {
    std::vector<std::pair<int, int>> seats_to_book = { {0, 0} };
    system->book_ticket("Batman", seats_to_book);
    std::string result = system->book_ticket("Batman", seats_to_book);
    EXPECT_EQ(result, "Booking failed.");
    EXPECT_EQ(system->movies[0].seats[0][0], 1);
}

TEST_F(MovieBookingSystemTestBookTicket, test_book_ticket_3) {
    std::vector<std::pair<int, int>> seats_to_book = { {0, 0} };
    std::string result = system->book_ticket("batman", seats_to_book);
    EXPECT_EQ(result, "Movie not found.");
    EXPECT_EQ(system->movies[0].seats[0][0], 0);
}

TEST_F(MovieBookingSystemTestBookTicket, test_book_ticket_4) {
    std::vector<std::pair<int, int>> seats_to_book = { {0, 0}, {1, 1} };
    std::string result = system->book_ticket("Batman", seats_to_book);
    EXPECT_EQ(result, "Booking success.");
    EXPECT_EQ(system->movies[0].seats[0][0], 1);
    EXPECT_EQ(system->movies[0].seats[1][1], 1);
}

TEST_F(MovieBookingSystemTestBookTicket, test_book_ticket_5) {
    std::vector<std::pair<int, int>> seats_to_book = { {0, 0} };
    std::string result = system->book_ticket("Batman", seats_to_book);
    EXPECT_EQ(result, "Booking success.");
    EXPECT_EQ(system->movies[0].seats[0][0], 1);
}

class MovieBookingSystemTestAvailableMovies : public ::testing::Test {
protected:
    MovieBookingSystem* system;

    void SetUp() override {
        system = new MovieBookingSystem();
        system->add_movie("Batman", 49.9, "17:05", "19:25", 3);
        system->add_movie("Spiderman", 59.9, "20:00", "22:30", 4);
    }

    void TearDown() override {
        delete system;
    }
};

TEST_F(MovieBookingSystemTestAvailableMovies, test_available_movies_1) {
    std::vector<std::string> result = system->available_movies("16:00", "23:00");
    std::vector<std::string> expected = { "Batman", "Spiderman" };
    EXPECT_EQ(result, expected);
}

TEST_F(MovieBookingSystemTestAvailableMovies, test_available_movies_2) {
    std::vector<std::string> result = system->available_movies("23:00", "23:59");
    std::vector<std::string> expected = {};
    EXPECT_EQ(result, expected);
}

TEST_F(MovieBookingSystemTestAvailableMovies, test_available_movies_3) {
    std::vector<std::string> result = system->available_movies("17:00", "20:00");
    std::vector<std::string> expected = { "Batman" };
    EXPECT_EQ(result, expected);
}

TEST_F(MovieBookingSystemTestAvailableMovies, test_available_movies_4) {
    std::vector<std::string> result = system->available_movies("10:00", "23:00");
    std::vector<std::string> expected = { "Batman", "Spiderman" };
    EXPECT_EQ(result, expected);
}

TEST_F(MovieBookingSystemTestAvailableMovies, test_available_movies_5) {
    std::vector<std::string> result = system->available_movies("20:00", "23:00");
    std::vector<std::string> expected = { "Spiderman" };
    EXPECT_EQ(result, expected);
}

class MovieBookingSystemTestMain : public ::testing::Test {
protected:
    MovieBookingSystem* system;

    void SetUp() override {
        system = new MovieBookingSystem();
        system->add_movie("Batman", 49.9, "17:05", "19:25", 3);
    }

    void TearDown() override {
        delete system;
    }
};

TEST_F(MovieBookingSystemTestMain, test_main) {
    
    EXPECT_EQ(system->movies.size(), 1);
    EXPECT_EQ(system->movies[0].name, "Batman");
    EXPECT_EQ(system->movies[0].price, 49.9);
    EXPECT_EQ(system->movies[0].start_time.tm_hour, 17);
    EXPECT_EQ(system->movies[0].start_time.tm_min, 5);
    EXPECT_EQ(system->movies[0].end_time.tm_hour, 19);
    EXPECT_EQ(system->movies[0].end_time.tm_min, 25);
    EXPECT_EQ(system->movies[0].seats.size(), 3);
    EXPECT_EQ(system->movies[0].seats[0].size(), 3);

    
    std::vector<std::pair<int, int>> seats_to_book = { {0, 0}, {1, 1}, {2, 2} };
    std::string result = system->book_ticket("Batman", seats_to_book);
    EXPECT_EQ(result, "Booking success.");
    EXPECT_EQ(system->movies[0].seats[0][0], 1);
    EXPECT_EQ(system->movies[0].seats[1][1], 1);
    EXPECT_EQ(system->movies[0].seats[2][2], 1);

    
    std::vector<std::string> available_movies = system->available_movies("16:00", "23:00");
    std::vector<std::string> expected = { "Batman" };
    EXPECT_EQ(available_movies, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}