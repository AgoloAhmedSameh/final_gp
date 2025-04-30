#include <vector>
#include <unordered_map>

std::pair<std::vector<std::string>, std::vector<std::string>> get_key(const std::unordered_map<std::string, std::string>& dict) {
    std::vector<std::string> list;
    for (const auto& pair : dict) {
        list.push_back(pair.first);
    }
    return {list};
}
