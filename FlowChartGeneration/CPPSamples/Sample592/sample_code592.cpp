#include <iostream>
#include <regex>
#include <string>

std::string removezero_ip(const std::string& ip) {
    std::regex pattern("\\.[0]*");
    return std::regex_replace(ip, pattern, ".");
}
