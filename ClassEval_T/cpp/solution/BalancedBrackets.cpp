
#include <algorithm>

#include <stack>
#include <string>

class BalancedBrackets {
public:
    explicit BalancedBrackets(const std::string& expr);
    bool check_balanced_brackets();

    void clearExpr();

    std::stack<char> stack;
    const std::string leftBrackets = "({[";
    const std::string rightBrackets = ")}]";
    std::string expr;
};

BalancedBrackets::BalancedBrackets(const std::string& expr) : expr(expr) {}

void BalancedBrackets::clearExpr() {
    expr.erase(std::remove_if(expr.begin(), expr.end(), [this](char c) {
        return leftBrackets.find(c) == std::string::npos && rightBrackets.find(c) == std::string::npos;
        }), expr.end());
}

bool BalancedBrackets::check_balanced_brackets() {
    clearExpr();
    for (char Brkt : expr) {
        if (leftBrackets.find(Brkt) != std::string::npos) {
            stack.push(Brkt);
        }
        else {
            if (stack.empty()) return false;
            char Current_Brkt = stack.top();
            stack.pop();
            if (Current_Brkt == '(' && Brkt != ')') return false;
            if (Current_Brkt == '{' && Brkt != '}') return false;
            if (Current_Brkt == '[' && Brkt != ']') return false;
        }
    }
    return stack.empty();
}
