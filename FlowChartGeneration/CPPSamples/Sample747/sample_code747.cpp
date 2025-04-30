#include <string>
#include <regex>

std::string capital_words_spaces(const std::string &str1) {
    return std::regex_replace(str1, std::regex(R"((\w)([A-Z]))"), "$1 $2");
}
