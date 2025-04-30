#include <iostream>
#include <string>
#include <regex>

std::tuple<std::string, int, int> find_literals(const std::string& text, const std::string& pattern) {
    std::regex re(pattern);
    std::smatch match;
    if (std::regex_search(text, match, re)) {
        int s = match.position();
        int e = s + match.length();
        return std::make_tuple(match.str(), s, e);
    }
    return std::make_tuple("", -1, -1);
}

int main() {
    std::string pattern = "fox";
    std::string text = "The quick brown fox jumps over the lazy dog.";
    auto result = find_literals(text, pattern);
    return 0;
}
