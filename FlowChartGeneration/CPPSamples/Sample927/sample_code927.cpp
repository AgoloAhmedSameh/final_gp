#include <iostream>
#include <regex>
#include <string>

std::string change_date_format(const std::string &dt) {
    return std::regex_replace(dt, std::regex(R"((\d{4})-(\d{1,2})-(\d{1,2}))"), "$3-$2-$1");
}
