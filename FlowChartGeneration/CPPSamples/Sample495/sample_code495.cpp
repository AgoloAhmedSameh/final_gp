#include <vector>
#include <queue>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> heap_queue_smallest(std::vector<int>& nums, int n) {
    std::vector<int> smallest_nums;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin(), nums.end());
    for (int i = 0; i < n && !min_heap.empty(); ++i) {
        smallest_nums.push_back(min_heap.top());
        min_heap.pop();
    }
    return {smallest_nums};
}
