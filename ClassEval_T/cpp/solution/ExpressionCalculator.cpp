
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <cctype>

#include <deque>
#include <string>
#include <stdexcept>
#include <regex>
#include <cctype>
#include <unordered_map>
#include <vector>

class ExpressionCalculator {
public:
    ExpressionCalculator();

    double calculate(const std::string& expression);
    void prepare(const std::string& expression);
    static bool is_operator(const std::string& c);
    bool compare(const std::string& cur, const std::string& peek);
    static double _calculate(const std::string& first_value, const std::string& second_value, const std::string& current_op);
    static std::string transform(const std::string& expression);

    std::deque<std::string> postfix_stack;

private:
    std::vector<int> operat_priority;
};

ExpressionCalculator::ExpressionCalculator() : operat_priority{ 0, 3, 2, 1, -1, 1, 0, 2 } {}

double ExpressionCalculator::calculate(const std::string& expression) {
    prepare(transform(expression));

    std::deque<std::string> result_stack;
    std::deque<std::string> reversed_postfix_stack = postfix_stack;
    std::reverse(reversed_postfix_stack.begin(), reversed_postfix_stack.end());

    while (!reversed_postfix_stack.empty()) {
        std::string current_op = reversed_postfix_stack.back();
        reversed_postfix_stack.pop_back();

        if (!is_operator(current_op)) {
            current_op = std::regex_replace(current_op, std::regex("~"), "-");
            result_stack.push_back(current_op);
        }
        else {
            std::string second_value = result_stack.back();
            result_stack.pop_back();
            std::string first_value = result_stack.back();
            result_stack.pop_back();

            first_value = std::regex_replace(first_value, std::regex("~"), "-");
            second_value = std::regex_replace(second_value, std::regex("~"), "-");

            double temp_result = _calculate(first_value, second_value, current_op);
            result_stack.push_back(std::to_string(temp_result));
        }
    }

    std::string result_str = "";
    for (const auto& val : result_stack) {
        result_str += val + "*";
    }
    result_str.pop_back(); 
    return std::stod(result_str); 
}

void ExpressionCalculator::prepare(const std::string& expression) {
    std::deque<std::string> op_stack{ "," };
    std::string arr = expression;
    size_t current_index = 0;
    size_t count = 0;
    postfix_stack.clear();
    for (size_t i = 0; i < arr.length(); ++i) {
        std::string current_op(1, arr[i]);

        if (is_operator(current_op)) {
            if (count > 0) {
                postfix_stack.push_back(arr.substr(current_index, count));
            }
            std::string peek_op = op_stack.back();

            if (current_op == ")") {
                while (op_stack.back() != "(") {
                    postfix_stack.push_back(op_stack.back());
                    op_stack.pop_back();
                }
                op_stack.pop_back();
            }
            else {
                while (current_op != "(" && peek_op != "," && compare(current_op, peek_op)) {
                    postfix_stack.push_back(op_stack.back());
                    op_stack.pop_back();
                    peek_op = op_stack.back();
                }
                op_stack.push_back(current_op);
            }

            count = 0;
            current_index = i + 1;
        }
        else {
            ++count;
        }
    }

    if (count > 1 || (count == 1 && !is_operator(arr.substr(current_index, count)))) {
        postfix_stack.push_back(arr.substr(current_index, count));
    }

    while (op_stack.back() != ",") {
        postfix_stack.push_back(op_stack.back());
        op_stack.pop_back();
    }
}

bool ExpressionCalculator::is_operator(const std::string& c) {
    static const std::unordered_map<std::string, bool> operators{
        {"+", true}, {"-", true}, {"*", true}, {"/", true}, {"(", true}, {")", true}, {"%", true}
    };
    return operators.find(c) != operators.end();
}

bool ExpressionCalculator::compare(const std::string& cur, const std::string& peek) {
    std::string cur_op = cur == "%" ? "/" : cur;
    std::string peek_op = peek == "%" ? "/" : peek;
    return operat_priority[peek_op[0] - 40] >= operat_priority[cur_op[0] - 40];
}

double ExpressionCalculator::_calculate(const std::string& first_value, const std::string& second_value, const std::string& current_op) {
    double f = std::stod(first_value);
    double s = std::stod(second_value);

    if (current_op == "+") return f + s;
    if (current_op == "-") return f - s;
    if (current_op == "*") return f * s;
    if (current_op == "/") return f / s;
    if (current_op == "%") return std::fmod(f, s);

    throw std::invalid_argument("Unexpected operator: " + current_op);
}

std::string ExpressionCalculator::transform(const std::string& expression) {
    std::string expr = std::regex_replace(expression, std::regex("\\s+"), "");
    expr = std::regex_replace(expr, std::regex("=$"), "");

    for (size_t i = 0; i < expr.length(); ++i) {
        if (expr[i] == '-') {
            if (i == 0) {
                expr[i] = '~';
            }
            else {
                char prev_c = expr[i - 1];
                if (prev_c == '+' || prev_c == '-' || prev_c == '*' || prev_c == '/' || prev_c == '(' || prev_c == 'E' || prev_c == 'e') {
                    expr[i] = '~';
                }
            }
        }
    }

    if (expr[0] == '~' && expr.length() > 1 && expr[1] == '(') {
        expr[0] = '-';
        return "0" + expr;
    }
    else {
        return expr;
    }
}
