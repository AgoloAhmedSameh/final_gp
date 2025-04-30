#include <vector>
#include <string>
#include <optional>

std::optional<std::string> longest(const std::vector<std::string>& strings) {
    if (strings.empty()) {
        return std::nullopt;
    }

    size_t maxlen = 0;
    for (const auto& s : strings) {
        maxlen = std::max(maxlen, s.length());
    }
    
    for (const auto& s : strings) {
        if (s.length() == maxlen) {
            return s;
        }
    }

    return std::nullopt;
}
