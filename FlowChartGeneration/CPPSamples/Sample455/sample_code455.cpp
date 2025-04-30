#include <vector>
#include <string>
#include <algorithm>

std::pair<std::vector<std::string>, std::vector<std::string>> reverse_string_list(const std::vector<std::string>& stringlist) {
    std::vector<std::string> result;
    for (const auto& x : stringlist) {
        std::string reversed = x;
        std::reverse(reversed.begin(), reversed.end());
        result.push_back(reversed);
    }
    return {result, {}};
}
