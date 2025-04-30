#include <vector>
#include <string>
#include <regex>

std::vector<std::string> remove(const std::vector<std::string>& list) {
    std::regex pattern("[0-9]");
    std::vector<std::string> result;
    
    for (const auto& i : list) {
        result.push_back(std::regex_replace(i, pattern, ""));
    }
    
    return result;
}
