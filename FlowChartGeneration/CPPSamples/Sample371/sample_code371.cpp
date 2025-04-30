#include <vector>
#include <queue>

std::pair<std::vector<int>, std::vector<int>> heap_assending(std::vector<int> nums) {
    std::make_heap(nums.begin(), nums.end(), std::greater<int>());
    std::vector<int> s_result;
    while (!nums.empty()) {
        std::pop_heap(nums.begin(), nums.end(), std::greater<int>());
        s_result.push_back(nums.back());
        nums.pop_back();
    }
    return {s_result};
}
