#include <vector>
#include <string>

std::pair<int, int> len_log(const std::vector<std::string>& list1) {
    int max = list1[0].length();
    for (const auto& i : list1) {
        if (i.length() > max) {
            max = i.length();
        }
    }
    return {max, 0}; // Assuming you want to return a second value as per the original function signature
}
