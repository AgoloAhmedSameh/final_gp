#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> permute_string(const std::string& str) {
    if (str.length() == 0) {
        return {""};
    }
    std::vector<std::string> prev_list = permute_string(str.substr(1));
    std::vector<std::string> next_list;
    for (const auto& s : prev_list) {
        for (size_t j = 0; j <= str.length(); ++j) {
            std::string new_str = s.substr(0, j) + str[0] + s.substr(j);
            if (std::find(next_list.begin(), next_list.end(), new_str) == next_list.end()) {
                next_list.push_back(new_str);
            }
        }
    }
    return next_list;
}
