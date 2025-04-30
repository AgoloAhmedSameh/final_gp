#include <string>

std::string check_Equality(const std::string& str) {
    if (str[0] == str[str.length() - 1]) {
        return "Equal";
    } else {
        return "Not Equal";
    }
}
