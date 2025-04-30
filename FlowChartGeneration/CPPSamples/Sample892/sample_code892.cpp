#include <vector>
#include <string>

std::vector<std::string> Extract(const std::vector<std::vector<std::string>>& lst) {
    std::vector<std::string> result;
    for (const auto& item : lst) {
        if (!item.empty()) {
            result.push_back(item.back());
        }
    }
    return result;
}
