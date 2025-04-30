#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::tuple<std::vector<char>, std::vector<char>, std::vector<char>, std::vector<char>> find_character(const std::string& str) {
    std::vector<char> uppercase_characters;
    std::vector<char> lowercase_characters;
    std::vector<char> numerical_characters;
    std::vector<char> special_characters;

    std::regex uppercase_regex("[A-Z]");
    std::regex lowercase_regex("[a-z]");
    std::regex numerical_regex("[0-9]");
    std::regex special_regex("[, .!?]");

    for (char ch : str) {
        if (std::regex_match(std::string(1, ch), uppercase_regex)) {
            uppercase_characters.push_back(ch);
        }
        if (std::regex_match(std::string(1, ch), lowercase_regex)) {
            lowercase_characters.push_back(ch);
        }
        if (std::regex_match(std::string(1, ch), numerical_regex)) {
            numerical_characters.push_back(ch);
        }
        if (std::regex_match(std::string(1, ch), special_regex)) {
            special_characters.push_back(ch);
        }
    }

    return {uppercase_characters, lowercase_characters, numerical_characters, special_characters};
}
