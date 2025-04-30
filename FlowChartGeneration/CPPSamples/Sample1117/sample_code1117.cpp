#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::string words_in_sentence(const std::string& sentence) {
    std::vector<std::string> new_lst;
    std::istringstream iss(sentence);
    std::string word;

    while (iss >> word) {
        bool flg = false;
        if (word.length() == 1) {
            flg = true;
        }
        for (size_t i = 2; i < word.length(); ++i) {
            if (word.length() % i == 0) {
                flg = true;
                break;
            }
        }
        if (!flg || word.length() == 2) {
            new_lst.push_back(word);
        }
    }

    std::string result;
    for (size_t i = 0; i < new_lst.size(); ++i) {
        result += new_lst[i];
        if (i < new_lst.size() - 1) {
            result += " ";
        }
    }
    return result;
}
