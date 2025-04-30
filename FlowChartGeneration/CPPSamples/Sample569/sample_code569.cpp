#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::pair<std::vector<std::string>, std::vector<std::string>> remove_words(const std::vector<std::string>& list1, const std::vector<std::string>& charlist) {
    std::vector<std::string> new_list;

    for (const auto& line : list1) {
        std::istringstream iss(line);
        std::string word;
        std::string new_words;

        while (iss >> word) {
            bool found = false;
            for (const auto& phrase : charlist) {
                if (word.find(phrase) != std::string::npos) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (!new_words.empty()) {
                    new_words += " ";
                }
                new_words += word;
            }
        }

        new_list.push_back(new_words);
    }

    return {new_list, {}};
}
