#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<std::string>> remove_empty(const std::vector<std::tuple<std::string>>& tuple1) {
    std::vector<std::tuple<std::string>> result;
    for (const auto& t : tuple1) {
        if (!std::get<0>(t).empty()) {
            result.push_back(t);
        }
    }
    return result;
}
