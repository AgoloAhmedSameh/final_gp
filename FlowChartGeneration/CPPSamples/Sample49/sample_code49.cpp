#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

std::tuple<int, std::string> min_length_list(const std::vector<std::string>& input_list) {
    int min_length = std::min_element(input_list.begin(), input_list.end(),
                                       [](const std::string& a, const std::string& b) {
                                           return a.length() < b.length();
                                       })->length();
    std::string min_list = *std::min_element(input_list.begin(), input_list.end(),
                                             [](const std::string& a, const std::string& b) {
                                                 return a.length() < b.length();
                                             });
    return std::make_tuple(min_length, min_list);
}
