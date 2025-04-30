#include <vector>
#include <string>

std::vector<std::string> filter_by_prefix(const std::vector<std::string>& strings, const std::string& prefix) {
    std::vector<std::string> result;
    for (const auto& x : strings) {
        if (x.find(prefix) == 0) {
            result.push_back(x);
        }
    }
    return result;
}
