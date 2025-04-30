#include <vector>
#include <string>
#include <algorithm>

std::pair<std::vector<std::string>, std::vector<std::string>> palindrome_lambda(const std::vector<std::string>& texts) {
    std::vector<std::string> result;
    for (const auto& x : texts) {
        if (x == std::string(x.rbegin(), x.rend())) {
            result.push_back(x);
        }
    }
    return {result};
}
