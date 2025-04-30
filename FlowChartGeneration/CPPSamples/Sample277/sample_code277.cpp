#include <tuple>
#include <variant>
#include <vector>

std::pair<int, int> count_first_elements(const std::vector<std::variant<int, std::tuple<int>>>& test_tup) {
    int count = 0;
    for (const auto& ele : test_tup) {
        if (std::holds_alternative<std::tuple<int>>(ele)) {
            break;
        }
        count++;
    }
    return {count, 0}; // Returning a pair with the count and 0 as the second element
}
