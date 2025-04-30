#include <unordered_map>

std::pair<int, int> return_sum(const std::unordered_map<std::string, int>& dict) {
    int sum = 0;
    for (const auto& pair : dict) {
        sum += pair.second;
    }
    return {sum, 0}; // To match the return type, assuming the second value is 0
}
