#include <string>
#include <vector>
#include <regex>

std::tuple<std::vector<std::string>> extract_values(const std::string& text) {
    std::regex pattern(R"("([^"]*)")");
    std::vector<std::string> results;
    for (std::sregex_iterator it = std::sregex_iterator(text.begin(), text.end(), pattern);
         it != std::sregex_iterator(); ++it) {
        results.push_back(it->str(1));
    }
    return std::make_tuple(results);
}
