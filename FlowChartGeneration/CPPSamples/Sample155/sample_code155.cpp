#include <tuple>
#include <vector>

std::vector<std::tuple<int, int>> tuple_int_str(const std::vector<std::tuple<std::string, std::string>>& tuple_str) {
    std::vector<std::tuple<int, int>> result;
    for (const auto& x : tuple_str) {
        result.emplace_back(std::stoi(std::get<0>(x)), std::stoi(std::get<1>(x)));
    }
    return result;
}
