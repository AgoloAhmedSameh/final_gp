#include <vector>
#include <tuple>
#include <map>

std::pair<std::map<std::tuple<int, int>, int>, std::vector<int>> unique_sublists(const std::vector<std::vector<int>>& list1) {
    std::map<std::tuple<int, int>, int> result;
    
    for (const auto& l : list1) {
        auto t = std::make_tuple(l[0], l[1]); // Assuming sublists are of size 2
        result[t]++;
    }

    return {result, {}};
}
