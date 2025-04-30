#include <vector>
#include <string>
#include <algorithm>
#include <limits>

std::pair<int, int> Find_Min_Length(const std::vector<std::string>& lst) {
    int minLength = std::numeric_limits<int>::max();
    for (const auto& x : lst) {
        minLength = std::min(minLength, static_cast<int>(x.length()));
    }
    return {minLength, 0}; // Adjust the second return value as needed
}
