#include <unordered_map>

std::pair<bool, bool> check_value(const std::unordered_map<std::string, int>& dict, int n) {
    bool result = true;
    for (const auto& pair : dict) {
        if (pair.second != n) {
            result = false;
            break;
        }
    }
    return {result, result}; // The second value is the same as the first in this conversion
}
