#include <iostream>
#include <vector>
#include <regex>
#include <string>

std::pair<std::string, std::string> start_withp(const std::vector<std::string>& words) {
    std::regex pattern("(P\\w+)\\W(P\\w+)");
    for (const auto& w : words) {
        std::smatch m;
        if (std::regex_match(w, m, pattern)) {
            return {m[1], m[2]};
        }
    }
    return {"", ""}; // return an empty pair if no match is found
}
