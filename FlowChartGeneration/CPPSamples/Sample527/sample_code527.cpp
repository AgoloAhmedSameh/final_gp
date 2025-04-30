#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

std::tuple<int, std::string> min_length(const std::vector<std::string>& list1) {
    int min_length = std::min_element(list1.begin(), list1.end(), 
                                       [](const std::string& a, const std::string& b) {
                                           return a.length() < b.length();
                                       })->length();
    std::string min_list = *std::min_element(list1.begin(), list1.end());
    return std::make_tuple(min_length, min_list);
}
