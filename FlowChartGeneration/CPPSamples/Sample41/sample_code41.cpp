#include <vector>
#include <unordered_map>

std::pair<int, int> find_Sum(std::vector<int>& arr, int n) {
    std::unordered_map<int, int> count_map;
    for (int x : arr) {
        count_map[x]++;
    }
    
    int sum = 0;
    for (const auto& pair : count_map) {
        if (pair.second > 1) {
            sum += pair.first;
        }
    }
    
    return {sum, 0}; // Return a pair with the sum and a placeholder
}
