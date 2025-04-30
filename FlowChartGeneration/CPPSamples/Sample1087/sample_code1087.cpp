#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> odd_count(const std::vector<std::string>& lst) {
    std::vector<std::string> res;
    for (const auto& arr : lst) {
        int n = 0;
        for (char d : arr) {
            if (isdigit(d) && (d - '0') % 2 == 1) {
                n++;
            }
        }
        res.push_back("the number of odd elements " + std::to_string(n) + " in the str" + std::to_string(n) + "ng " + std::to_string(n) + " of the " + std::to_string(n) + "nput.");
    }
    return res;
}
