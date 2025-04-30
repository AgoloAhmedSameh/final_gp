#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> split_words(const std::string& txt) {
    if (txt.find(" ") != std::string::npos) {
        std::istringstream iss(txt);
        std::vector<std::string> words;
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    } else if (txt.find(",") != std::string::npos) {
        std::string modified_txt = txt;
        std::replace(modified_txt.begin(), modified_txt.end(), ',', ' ');
        std::istringstream iss(modified_txt);
        std::vector<std::string> words;
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    } else {
        int count = 0;
        for (char i : txt) {
            if (std::islower(i) && (static_cast<int>(i) % 2 == 0)) {
                count++;
            }
        }
        return std::vector<std::string>{std::to_string(count)};
    }
}
