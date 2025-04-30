#include <vector>
#include <typeinfo>

std::pair<int, int> count_integer(const std::vector<std::variant<int, double, std::string>>& list1) {
    int ctr = 0;
    for (const auto& i : list1) {
        if (std::holds_alternative<int>(i)) {
            ctr++;
        }
    }
    return {ctr, 0}; // Returning a second value as a placeholder
}
