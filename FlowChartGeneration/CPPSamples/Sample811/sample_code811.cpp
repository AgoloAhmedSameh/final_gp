#include <string>
#include <regex>

std::string road_rd(const std::string& street) {
    return std::regex_replace(street, std::regex("Road$"), "Rd.");
}
