#include <iostream>
#include <map>
#include <unordered_map>

std::map<std::string, std::string> merge_dictionaries(const std::map<std::string, std::string>& dict1, const std::map<std::string, std::string>& dict2) {
    std::map<std::string, std::string> merged_dict = dict2;
    merged_dict.insert(dict1.begin(), dict1.end());
    return merged_dict;
}
