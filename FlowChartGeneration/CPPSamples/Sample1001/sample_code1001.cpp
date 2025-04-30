#include <string>
#include <cctype>

std::string flip_case(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (std::isupper(ch)) {
            result += std::tolower(ch);
        } else {
            result += std::toupper(ch);
        }
    }
    return result;
}
