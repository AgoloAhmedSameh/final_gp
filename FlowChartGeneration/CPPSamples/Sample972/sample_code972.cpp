#include <string>

std::pair<std::string, std::string> left_rotate(const std::string& s, int d) {
    std::string tmp = s.substr(d) + s.substr(0, d);
    return {tmp, tmp};
}
