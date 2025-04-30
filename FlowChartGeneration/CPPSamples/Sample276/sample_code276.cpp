#include <map>
#include <vector>

std::map<std::string, int> dict_filter(const std::map<std::string, int>& dict, int n) {
    std::map<std::string, int> result;
    for (const auto& pair : dict) {
        if (pair.second >= n) {
            result[pair.first] = pair.second;
        }
    }
    return result;
}
