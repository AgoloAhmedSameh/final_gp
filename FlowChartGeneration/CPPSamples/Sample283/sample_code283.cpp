#include <vector>

std::pair<bool, bool> check_element(const std::vector<int>& list, int element) {
    bool check_element = std::all_of(list.begin(), list.end(), [element](int v) { return v == element; });
    return {check_element, check_element};
}
