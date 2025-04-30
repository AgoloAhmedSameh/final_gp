#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

std::tuple<int, std::string> max_length(const std::vector<std::string>& list1) {
    int max_length = 0;
    std::string max_list;

    for (const auto& x : list1) {
        if (x.length() > max_length) {
            max_length = x.length();
            max_list = x;
        }
    }

    return std::make_tuple(max_length, max_list);
}
