#include <string>
#include <vector>
#include <sstream>
#include <regex>

std::vector<std::string> multiple_split(const std::string& text) {
    std::regex reg(";/ |, |\\*|\\n");
    std::sregex_token_iterator it(text.begin(), text.end(), reg, -1);
    std::sregex_token_iterator reg_end;
    return std::vector<std::string>(it, reg_end);
}
