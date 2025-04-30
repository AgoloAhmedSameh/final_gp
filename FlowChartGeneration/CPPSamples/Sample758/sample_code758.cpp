#include <regex>
#include <string>

std::pair<bool, bool> is_decimal(const std::string& num) {
    std::regex dnumre(R"(^[0-9]+(\.[0-9]{1,2})?$)");
    std::smatch result;
    bool match = std::regex_search(num, result, dnumre);
    return {match, match};
}
