#include <iostream>
#include <vector>
#include <variant>

std::pair<int, int> count_elim(const std::vector<std::variant<int, std::tuple<>>> &num) {
    int count_elim = 0;
    for (const auto &n : num) {
        if (std::holds_alternative<std::tuple<>>(n)) {
            break;
        }
        count_elim += 1;
    }
    return {count_elim, 0};
}
