#include <vector>
#include <string>
#include <algorithm>

std::pair<std::vector<int>, std::vector<std::string>> sort_mixed_list(const std::vector<std::variant<int, std::string>>& mixed_list) {
    std::vector<int> int_part;
    std::vector<std::string> str_part;

    for (const auto& item : mixed_list) {
        if (std::holds_alternative<int>(item)) {
            int_part.push_back(std::get<int>(item));
        } else if (std::holds_alternative<std::string>(item)) {
            str_part.push_back(std::get<std::string>(item));
        }
    }

    std::sort(int_part.begin(), int_part.end());
    std::sort(str_part.begin(), str_part.end());

    int_part.insert(int_part.end(), str_part.begin(), str_part.end());
    return {int_part, str_part};
}
