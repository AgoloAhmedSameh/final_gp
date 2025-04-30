#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> add_string(const std::vector<std::string>& list, const std::string& string) {
    std::vector<std::string> add_string;
    for (const auto& i : list) {
        add_string.push_back(fmt::format(string, i));
    }
    return add_string;
}
