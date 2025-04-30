#include <map>
#include <unordered_map>

std::map<std::string, std::string> merge_dictionaries_three(
    const std::unordered_map<std::string, std::string>& dict1,
    const std::unordered_map<std::string, std::string>& dict2,
    const std::unordered_map<std::string, std::string>& dict3) {
    
    std::map<std::string, std::string> merged_dict;

    for (const auto& [key, value] : dict3) {
        merged_dict[key] = value;
    }
    for (const auto& [key, value] : dict2) {
        merged_dict.emplace(key, value);
    }
    for (const auto& [key, value] : dict1) {
        merged_dict.emplace(key, value);
    }

    return merged_dict;
}
