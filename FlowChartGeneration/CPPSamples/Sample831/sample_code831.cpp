#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

std::pair<int, bool> extract_max(const std::string& input) {
    std::regex rgx("\\d+");
    std::sregex_iterator it(input.begin(), input.end(), rgx);
    std::sregex_iterator end;

    std::vector<int> numbers;
    while (it != end) {
        numbers.push_back(std::stoi(it->str()));
        ++it;
    }

    if (!numbers.empty()) {
        return { *std::max_element(numbers.begin(), numbers.end()), true };
    } else {
        return { 0, false }; // Return 0 and false if no numbers found
    }
}
