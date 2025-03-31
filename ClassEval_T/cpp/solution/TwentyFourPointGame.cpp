
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>

#include <vector>
#include <stack>
#include <cmath>
#include <sstream>
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include <string>
#include <unordered_map>

class TwentyFourPointGame {
public:
    TwentyFourPointGame();
    std::vector<int> get_my_cards();
    std::vector<int> answer(const std::string& expression);
    bool evaluate_expression(const std::string& expression);
    void set_nums(std::vector<int> now);

private:
    void generate_cards();
    std::vector<int> nums;
};

class Calculator
{
public:
    Calculator();
    double calculate(const std::string& expression);
    int precedence(char op);
    std::pair<std::stack<double>, std::stack<char>> apply_operator(std::stack<double> operand_stack, std::stack<char> operator_stack);

private:
    std::unordered_map<char, std::function<double(double, double)>> operators;
};

TwentyFourPointGame::TwentyFourPointGame() {
    nums = {};
    std::srand(std::time(nullptr)); 
}

void TwentyFourPointGame::generate_cards() {
    for (int i = 0; i < 4; ++i) {
        nums.push_back(std::rand() % 9 + 1); 
    }
    assert(nums.size() == 4);
}

std::vector<int> TwentyFourPointGame::get_my_cards() {
    nums.clear();
    generate_cards();
    return nums;
}

std::vector<int> TwentyFourPointGame::answer(const std::string& expression) {
    if (expression == "pass") {
        return get_my_cards();
    }

    std::unordered_map<char, int> statistic;
    for (const char& c : expression) {
        if (std::isdigit(c) && std::find(nums.begin(), nums.end(), c - '0') != nums.end()) {
            statistic[c] = statistic[c] + 1;
        }
    }

    std::unordered_map<char, int> numsUsed = statistic;

    for (const int& num : nums) {
        if (numsUsed.find('0' + num) != numsUsed.end() && numsUsed['0' + num] > 0) {
            numsUsed['0' + num]--;
        }
        else {
            return {};
        }
    }

    if (std::all_of(numsUsed.begin(), numsUsed.end(), [](const auto& kv) { return kv.second == 0; })) {
        if (evaluate_expression(expression)) {
            return { 1 };
        }
        else {
            return {};
        }
    }
    else {
        return {};
    }
}

bool TwentyFourPointGame::evaluate_expression(const std::string& expression) {
    try {
        if (expression[0] < '0' || expression[0] > '9')
        {
            if(expression[0] != '(')
                throw(false);
        }
        int kkk = expression.size() - 1;
        if (expression[kkk] < '0' || expression[kkk] > '9')
        {
            if (expression[kkk] != ')')
                throw(false);
        }
        Calculator calculator;
        double ans = calculator.calculate(expression);

        if (ans == 24.0)
        {
            return true;
        }
        else return false;
    }
    catch (...) {
        return false;
    }
}

void TwentyFourPointGame::set_nums(std::vector<int> now)
{
    this->nums = now;
}


Calculator::Calculator()
{
    operators['+'] = [](double x, double y)
        { return x + y; };
    operators['-'] = [](double x, double y)
        { return x - y; };
    operators['*'] = [](double x, double y)
        { return x * y; };
    operators['/'] = [](double x, double y)
        { return x / y; };
    operators['^'] = [](double x, double y)
        { return std::pow(x, y); };
}

double Calculator::calculate(const std::string& expression)
{
    if (expression.empty())
    {
        return 0.0; 
    }

    std::stack<double> operand_stack;
    std::stack<char> operator_stack;
    std::string num_buffer;

    for (char ch : expression)
    {
        if (std::isdigit(ch) || ch == '.')
        {
            num_buffer += ch;
        }
        else
        {
            if (!num_buffer.empty())
            {
                operand_stack.push(std::stod(num_buffer));
                num_buffer.clear();
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            {
                while (!operator_stack.empty() && operator_stack.top() != '(' &&
                    precedence(operator_stack.top()) >= precedence(ch))
                {
                    auto [operands, operators] = apply_operator(operand_stack, operator_stack);
                    operand_stack = std::move(operands);
                    operator_stack = std::move(operators);
                }
                operator_stack.push(ch);
            }
            else if (ch == '(')
            {
                operator_stack.push(ch);
            }
            else if (ch == ')')
            {
                while (!operator_stack.empty() && operator_stack.top() != '(')
                {
                    auto [operands, operators] = apply_operator(operand_stack, operator_stack);
                    operand_stack = std::move(operands);
                    operator_stack = std::move(operators);
                }
                operator_stack.pop(); 
            }
        }
    }

    if (!num_buffer.empty())
    {
        operand_stack.push(std::stod(num_buffer));
    }

    while (!operator_stack.empty())
    {
        auto [operands, operators] = apply_operator(operand_stack, operator_stack);
        operand_stack = std::move(operands);
        operator_stack = std::move(operators);
    }

    return !operand_stack.empty() ? operand_stack.top() : 0.0; 
}

int Calculator::precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

std::pair<std::stack<double>, std::stack<char>> Calculator::apply_operator(std::stack<double> operand_stack, std::stack<char> operator_stack)
{
    char op = operator_stack.top();
    operator_stack.pop();

    double operand2 = operand_stack.top();
    operand_stack.pop();
    double operand1 = operand_stack.top();
    operand_stack.pop();

    double result = operators[op](operand1, operand2);
    operand_stack.push(result);

    return { operand_stack, operator_stack };
}