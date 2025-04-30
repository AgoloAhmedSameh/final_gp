#include <vector>
#include <string>
#include <algorithm>
#include <utility>

std::pair<int, std::string> max_length_list(const std::vector<std::string>& input_list) {
    int max_length = 0;
    std::string max_list;
    
    for (const auto& x : input_list) {
        if (x.length() > max_length) {
            max_length = x.length();
            max_list = x;
        }
    }
    
    return {max_length, max_list};
}
