#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<int> parse_nested_parens(const std::string& paren_string) {
    auto parse_paren_group = [](const std::string& s) {
        int depth = 0;
        int max_depth = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                max_depth = std::max(depth, max_depth);
            } else {
                depth--;
            }
        }
        return max_depth;
    };

    std::vector<int> result;
    std::istringstream iss(paren_string);
    std::string group;
    while (iss >> group) {
        if (!group.empty()) {
            result.push_back(parse_paren_group(group));
        }
    }
    return result;
}
