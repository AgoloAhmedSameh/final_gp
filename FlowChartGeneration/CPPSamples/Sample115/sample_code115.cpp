#include <iostream>
#include <vector>
#include <string>

std::pair<int, int> tuple_to_int(const std::vector<int>& nums) {
    std::string result_str;
    for (int num : nums) {
        result_str += std::to_string(num);
    }
    int result = std::stoi(result_str);
    return {result, result}; // Assuming you want to return the result twice as a pair
}
