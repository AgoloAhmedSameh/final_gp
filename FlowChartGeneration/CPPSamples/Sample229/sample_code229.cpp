#include <string>

std::pair<std::string, std::string> replace_blank(const std::string& str1, char ch) {
    std::string str2 = str1;
    std::replace(str2.begin(), str2.end(), ' ', ch);
    return {str2, ""};
}
