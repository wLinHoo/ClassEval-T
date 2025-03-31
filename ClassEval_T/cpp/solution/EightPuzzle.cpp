
#include <queue>
#include <algorithm>

#include <vector>
#include <string>

class EightPuzzle {
public:
    EightPuzzle(const std::vector<std::vector<int>>& initial_state);
    EightPuzzle(); 

    std::pair<int, int> find_blank(const std::vector<std::vector<int>>& state) const;
    std::vector<std::vector<int>> move(const std::vector<std::vector<int>>& state, const std::string& direction) const;
    std::vector<std::string> get_possible_moves(const std::vector<std::vector<int>>& state) const;
    std::vector<std::string> solve();
    EightPuzzle operator = (const std::vector<std::vector<int>>& initial_state);

private:
    std::vector<std::vector<int>> initialState;
    const std::vector<std::vector<int>> goalState = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };
};

EightPuzzle::EightPuzzle() : initialState({}) {}

EightPuzzle::EightPuzzle(const std::vector<std::vector<int>>& initial_state) : initialState(initial_state) {}

std::pair<int, int> EightPuzzle::find_blank(const std::vector<std::vector<int>>& state) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] == 0) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };  
}

std::vector<std::vector<int>> EightPuzzle::move(const std::vector<std::vector<int>>& state, const std::string& direction) const {
    auto [i, j] = find_blank(state);
    std::vector<std::vector<int>> newState = state;

    if (direction == "up" && i > 0) {
        std::swap(newState[i][j], newState[i - 1][j]);
    }
    else if (direction == "down" && i < 2) {
        std::swap(newState[i][j], newState[i + 1][j]);
    }
    else if (direction == "left" && j > 0) {
        std::swap(newState[i][j], newState[i][j - 1]);
    }
    else if (direction == "right" && j < 2) {
        std::swap(newState[i][j], newState[i][j + 1]);
    }

    return newState;
}

std::vector<std::string> EightPuzzle::get_possible_moves(const std::vector<std::vector<int>>& state) const {
    std::vector<std::string> moves;
    auto [i, j] = find_blank(state);

    if (i > 0) {
        moves.push_back("up");
    }
    if (i < 2) {
        moves.push_back("down");
    }
    if (j > 0) {
        moves.push_back("left");
    }
    if (j < 2) {
        moves.push_back("right");
    }

    return moves;
}

std::vector<std::string> EightPuzzle::solve() {
    std::queue<std::pair<std::vector<std::vector<int>>, std::vector<std::string>>> openList;
    std::vector<std::vector<std::vector<int>>> closedList;

    openList.push({ initialState, {} });

    while (!openList.empty()) {
        auto [currentState, path] = openList.front();
        openList.pop();
        closedList.push_back(currentState);

        if (currentState == goalState) {
            return path;
        }

        for (const auto& move : get_possible_moves(currentState)) {
            auto newState = this->move(currentState, move);
            if (std::find(closedList.begin(), closedList.end(), newState) == closedList.end()) {
                std::vector<std::string> newPath = path;
                newPath.push_back(move);
                openList.push({ newState, newPath });
            }
        }
    }

    return {};
}


EightPuzzle EightPuzzle::operator=(const std::vector<std::vector<int>>& initial_state)
{
    return EightPuzzle(initial_state);
}
