#include <iostream>
#include <vector>
#include <string>

std::pair<int, int> len_log(const std::vector<std::string>& list1) {
    int min = list1[0].length();
    for (const auto& i : list1) {
        if (i.length() < min) {
            min = i.length();
        }
    }
    return {min, 0}; // second value is a placeholder as the original function returns two values
}
