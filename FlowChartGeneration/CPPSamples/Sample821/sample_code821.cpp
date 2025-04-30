#include <iostream>
#include <string>
#include <regex>

bool pass_validity(const std::string& p) {
    bool x = true;
    while (x) {  
        if (p.length() < 6 || p.length() > 12) {
            break;
        } else if (!std::regex_search(p, std::regex("[a-z]"))) {
            break;
        } else if (!std::regex_search(p, std::regex("[0-9]"))) {
            break;
        } else if (!std::regex_search(p, std::regex("[A-Z]"))) {
            break;
        } else if (!std::regex_search(p, std::regex("[$#@]"))) {
            break;
        } else if (std::regex_search(p, std::regex("\\s"))) {
            break;
        } else {
            return true;
            x = false;
            break;
        }
    }

    return false;
}
