#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> func(const std::vector<std::vector<int>>& nums, int k) {
    std::unordered_map<int, int> d;
    for (const auto& row : nums) {
        for (int i : row) {
            d[i]++;
        }
    }
    
    std::vector<std::pair<int, int>> temp;
    for (const auto& [key, v] : d) {
        if (temp.size() < k) {
            temp.emplace_back(v, key);
            if (temp.size() == k) {
                std::make_heap(temp.begin(), temp.end());
            }
        } else {
            if (v > temp.front().first) {
                std::pop_heap(temp.begin(), temp.end());
                temp.pop_back();
                temp.emplace_back(v, key);
                std::push_heap(temp.begin(), temp.end());
            }
        }
    }

    std::vector<int> result;
    while (!temp.empty()) {
        std::pop_heap(temp.begin(), temp.end());
        result.push_back(temp.back().second);
        temp.pop_back();
    }
    return result;
}
