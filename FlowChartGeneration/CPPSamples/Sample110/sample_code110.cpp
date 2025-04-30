#include <vector>
#include <set>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> common_in_nested_lists(const std::vector<std::vector<int>>& nestedlist) {
    std::set<int> result_set;
    if (!nestedlist.empty()) {
        result_set = std::set<int>(nestedlist[0].begin(), nestedlist[0].end());
        for (const auto& list : nestedlist) {
            std::set<int> current_set(list.begin(), list.end());
            std::set<int> intersection;
            std::set_intersection(result_set.begin(), result_set.end(),
                                  current_set.begin(), current_set.end(),
                                  std::inserter(intersection, intersection.begin()));
            result_set = intersection;
        }
    }
    std::vector<int> result(result_set.begin(), result_set.end());
    return {result, {}};
}
