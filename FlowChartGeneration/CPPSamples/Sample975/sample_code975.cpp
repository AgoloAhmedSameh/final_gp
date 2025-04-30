#include <vector>
#include <string>

std::vector<std::string> separate_paren_groups(const std::string& paren_string) {
    std::vector<std::string> result;
    std::string current_string;
    int current_depth = 0;

    for (char c : paren_string) {
        if (c == '(') {
            current_depth++;
            current_string.push_back(c);
        } else if (c == ')') {
            current_depth--;
            current_string.push_back(c);

            if (current_depth == 0) {
                result.push_back(current_string);
                current_string.clear();
            }
        }
    }

    return result;
}
