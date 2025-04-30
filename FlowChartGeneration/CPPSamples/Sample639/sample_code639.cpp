#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> remove_parenthesis(const std::vector<std::string>& items) {
    std::regex pattern(" ?\\([^)]+\\)");
    std::vector<std::string> result;
    
    for (const auto& item : items) {
        result.push_back(std::regex_replace(item, pattern, ""));
    }
    
    return result;
}
