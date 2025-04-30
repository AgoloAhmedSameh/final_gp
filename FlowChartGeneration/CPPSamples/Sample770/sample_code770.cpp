#include <iostream>
#include <stack>
#include <string>

bool check_expression(const std::string& exp) {
    if (exp.length() % 2 != 0) {
        return false;
    }
    std::stack<char> stack;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((top == '(' && ch != ')') || (top == '{' && ch != '}') || (top == '[' && ch != ']')) {
                return false;
            }
        }
    }
    return stack.empty();
}
