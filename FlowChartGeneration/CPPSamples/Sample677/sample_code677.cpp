#include <string>

std::pair<std::string, std::string> remove_spaces(const std::string& str1) {
    std::string result = str1;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return {result, ""};
}
