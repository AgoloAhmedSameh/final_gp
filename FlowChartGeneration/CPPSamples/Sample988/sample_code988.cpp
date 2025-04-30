#include <vector>
#include <string>

std::vector<std::string> all_prefixes(const std::string& str) {
    std::vector<std::string> result;

    for (size_t i = 0; i < str.length(); ++i) {
        result.push_back(str.substr(0, i + 1));
    }
    return result;
}
