#include <regex>
#include <string>

std::string change_date_format(const std::string& dt) {
    std::regex pattern(R"((\d{4})-(\d{1,2})-(\d{1,2}))");
    return std::regex_replace(dt, pattern, "$3-$2-$1");
}
