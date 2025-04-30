#include <vector>
#include <queue>

std::vector<int> heap_queue_largest(const std::vector<int>& nums, int n) {
    std::priority_queue<int> pq(nums.begin(), nums.end());
    std::vector<int> largest_nums;
    for (int i = 0; i < n && !pq.empty(); ++i) {
        largest_nums.push_back(pq.top());
        pq.pop();
    }
    return largest_nums;
}
