#include <vector>
#include <algorithm>
#include <optional>

std::pair<std::optional<int>, std::optional<int>> largest_smallest_integers(const std::vector<int>& lst) {
    std::vector<int> smallest;
    std::vector<int> largest;

    for (int x : lst) {
        if (x < 0) {
            smallest.push_back(x);
        } else if (x > 0) {
            largest.push_back(x);
        }
    }

    std::optional<int> max_smallest = smallest.empty() ? std::nullopt : std::make_optional(*std::max_element(smallest.begin(), smallest.end()));
    std::optional<int> min_largest = largest.empty() ? std::nullopt : std::make_optional(*std::min_element(largest.begin(), largest.end()));

    return {max_smallest, min_largest};
}
