#include <tuple>
#include <string>
#include <vector>
#include <cctype>

std::tuple<std::vector<char>> string_list_to_tuple(const std::string& str1) {
    std::vector<char> result;
    for (char x : str1) {
        if (!std::isspace(x)) {
            result.push_back(x);
        }
    }
    return std::make_tuple(result);
}
