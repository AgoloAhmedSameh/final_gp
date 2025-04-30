#include <string>
#include <stack>
#include <unordered_map>

bool is_valid_parenthese(const std::string& str1) {
    std::stack<char> stack;
    std::unordered_map<char, char> pchar = { {'(', ')'}, {'{', '}'}, {'[', ']'} };
    
    for (char parenthese : str1) {
        if (pchar.find(parenthese) != pchar.end()) {
            stack.push(parenthese);
        } else if (stack.empty() || pchar[stack.top()] != parenthese) {
            return false;
        } else {
            stack.pop();
        }
    }
    return stack.empty();
}
