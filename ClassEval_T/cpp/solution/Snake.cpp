
#include <algorithm>
#include <random>
#include <ctime>

#include <vector>
#include <utility>

class Snake {
public:
    Snake(int screenWidth, int screenHeight, int blockSize, std::pair<int, int> foodPosition);

    void move(std::pair<int, int> direction);
    void random_food_position();
    void reset();
    void eat_food();

    int get_length() const;
    std::vector<std::pair<int, int>> get_positions() const;
    int get_score() const;
    std::pair<int, int> get_food_position() const;
    int get_SCREEN_WIDTH() const;
    int get_SCREEN_HEIGHT() const;
    int get_BLOCK_SIZE() const;

    int length;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int BLOCK_SIZE;
    std::vector<std::pair<int, int>> positions;
    int score;
    std::pair<int, int> food_position;
};

Snake::Snake(int screenWidth, int screenHeight, int blockSize, std::pair<int, int> foodPosition)
    : length(1), SCREEN_WIDTH(screenWidth), SCREEN_HEIGHT(screenHeight), BLOCK_SIZE(blockSize), score(0), food_position(foodPosition) {
    positions.push_back(std::make_pair(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
}

void Snake::move(std::pair<int, int> direction) {
    auto cur = positions[0];
    int x = direction.first;
    int y = direction.second;

    auto newPos = std::make_pair(
        (cur.first + x * BLOCK_SIZE) % SCREEN_WIDTH,
        (cur.second + y * BLOCK_SIZE) % SCREEN_HEIGHT
    );

    if (newPos == food_position) {
        eat_food();
    }

    if (positions.size() > 2 && std::find(positions.begin() + 2, positions.end(), newPos) != positions.end()) {
        reset();
    }
    else {
        positions.insert(positions.begin(), newPos);
        if (positions.size() > static_cast<size_t>(length)) {
            positions.pop_back();
        }
    }
}

void Snake::random_food_position() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    do {
        food_position = std::make_pair(
            (std::rand() % (SCREEN_WIDTH / BLOCK_SIZE)) * BLOCK_SIZE,
            (std::rand() % (SCREEN_HEIGHT / BLOCK_SIZE)) * BLOCK_SIZE
        );
    } while (std::find(positions.begin(), positions.end(), food_position) != positions.end());
}

void Snake::reset() {
    length = 1;
    positions = { std::make_pair(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2) };
    score = 0;
    random_food_position();
}

void Snake::eat_food() {
    length++;
    score += 100;
    random_food_position();
}

int Snake::get_length() const {
    return length;
}

std::vector<std::pair<int, int>> Snake::get_positions() const {
    return positions;
}

int Snake::get_score() const {
    return score;
}

std::pair<int, int> Snake::get_food_position() const {
    return food_position;
}

int Snake::get_SCREEN_WIDTH() const {
    return SCREEN_WIDTH;
}

int Snake::get_SCREEN_HEIGHT() const {
    return SCREEN_HEIGHT;
}

int Snake::get_BLOCK_SIZE() const {
    return BLOCK_SIZE;
}
