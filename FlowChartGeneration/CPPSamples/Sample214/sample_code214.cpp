#include <vector>
#include <tuple>
#include <variant>

std::vector<std::tuple<int, std::vector<int>>> decode_list(const std::vector<std::variant<int, std::vector<int>>>& alist) {
    auto aux = [](const std::variant<int, std::vector<int>>& g) {
        if (std::holds_alternative<std::vector<int>>(g)) {
            const auto& vec = std::get<std::vector<int>>(g);
            return std::make_tuple(vec[1], std::vector<int>(vec[0]));
        } else {
            return std::make_tuple(std::get<int>(g), std::vector<int>{0});
        }
    };

    std::vector<std::tuple<int, std::vector<int>>> result;
    for (const auto& g : alist) {
        auto [x, R] = aux(g);
        result.insert(result.end(), R.begin(), R.end());
    }
    return result;
}
