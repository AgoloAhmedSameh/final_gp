#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <string>
#include <algorithm>

std::pair<std::string> most_occurrences(const std::vector<std::string>& test_list) {
    std::unordered_map<std::string, int> temp;
    for (const auto& sub : test_list) {
        std::istringstream iss(sub);
        std::string wrd;
        while (iss >> wrd) {
            temp[wrd]++;
        }
    }
    auto res = std::max_element(temp.begin(), temp.end(), 
        [](const auto& a, const auto& b) { return a.second < b.second; });
    return { res->first };
}
