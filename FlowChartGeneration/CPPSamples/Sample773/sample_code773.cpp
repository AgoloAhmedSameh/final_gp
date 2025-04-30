#include <iostream>
#include <regex>
#include <string>

std::string check_email(const std::string& email) {
    std::regex pattern("^[a-z0-9]+[\\._]?[a-z0-9]+@[\\w]+[\\.]\\w{2,3}$");
    if (std::regex_match(email, pattern)) {
        return "Valid Email";
    } else {
        return "Invalid Email";
    }
}
