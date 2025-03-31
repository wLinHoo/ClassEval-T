
#include <sstream>

#include <string>
#include <stack>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <unordered_map>
#include <functional>

class Calculator {
public:
    Calculator();
    double calculate(const std::string& expression);
    int precedence(char op);
    std::pair<std::stack<double>, std::stack<char>> apply_operator(std::stack<double> operand_stack, std::stack<char> operator_stack);
private:
    std::unordered_map<char, std::function<double(double, double)>> operators;
};

Calculator::Calculator() {
    operators['+'] = [](double x, double y) { return x + y; };
    operators['-'] = [](double x, double y) { return x - y; };
    operators['*'] = [](double x, double y) { return x * y; };
    operators['/'] = [](double x, double y) { return x / y; };
    operators['^'] = [](double x, double y) { return std::pow(x, y); };
}

double Calculator::calculate(const std::string& expression) {
    if (expression.empty()) {
        return 0.0; 
    }

    std::stack<double> operand_stack;
    std::stack<char> operator_stack;
    std::string num_buffer;

    for (char ch : expression) {
        if (std::isdigit(ch) || ch == '.') {
            num_buffer += ch;
        }
        else {
            if (!num_buffer.empty()) {
                operand_stack.push(std::stod(num_buffer));
                num_buffer.clear();
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                while (!operator_stack.empty() && operator_stack.top() != '(' &&
                    precedence(operator_stack.top()) >= precedence(ch)) {
                    auto [operands, operators] = apply_operator(operand_stack, operator_stack);
                    operand_stack = std::move(operands);
                    operator_stack = std::move(operators);
                }
                operator_stack.push(ch);
            }
            else if (ch == '(') {
                operator_stack.push(ch);
            }
            else if (ch == ')') {
                while (!operator_stack.empty() && operator_stack.top() != '(') {
                    auto [operands, operators] = apply_operator(operand_stack, operator_stack);
                    operand_stack = std::move(operands);
                    operator_stack = std::move(operators);
                }
                operator_stack.pop(); 
            }
        }
    }

    if (!num_buffer.empty()) {
        operand_stack.push(std::stod(num_buffer));
    }

    while (!operator_stack.empty()) {
        auto [operands, operators] = apply_operator(operand_stack, operator_stack);
        operand_stack = std::move(operands);
        operator_stack = std::move(operators);
    }

    return !operand_stack.empty() ? operand_stack.top() : 0.0; 
}

int Calculator::precedence(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return 0;
    }
}

std::pair<std::stack<double>, std::stack<char>> Calculator::apply_operator(std::stack<double> operand_stack, std::stack<char> operator_stack) {
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
