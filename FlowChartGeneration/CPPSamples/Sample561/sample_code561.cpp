#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> Find_Max_Length(const std::vector<std::string>& lst) {
    int maxLength = 0;
    for (const auto& x : lst) {
        maxLength = std::max(maxLength, static_cast<int>(x.length()));
    }
    return {maxLength};
}
