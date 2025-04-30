#include <vector>
#include <tuple>
#include <map>
#include <iostream>

std::pair<std::vector<std::tuple<int, int>>, std::vector<std::tuple<int, int>>> group_tuples(const std::vector<std::tuple<int, int>>& Input) {
    std::map<int, std::vector<int>> out;
    for (const auto& elem : Input) {
        int key = std::get<0>(elem);
        std::vector<int> values = {std::get<1>(elem)};

        out[key].insert(out[key].end(), values.begin(), values.end());
    }

    std::vector<std::tuple<int, int>> result;
    for (const auto& pair : out) {
        result.emplace_back(pair.first, pair.second[0]);  // Adjust as necessary if the tuple has more elements
    }

    return {result};
}
