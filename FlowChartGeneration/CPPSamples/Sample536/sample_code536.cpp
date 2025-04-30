#include <iostream>
#include <set>
#include <sstream>
#include <string>

std::string first_repeated_word(const std::string &str1) {
    std::set<std::string> temp;
    std::istringstream iss(str1);
    std::string word;
    
    while (iss >> word) {
        if (temp.find(word) != temp.end()) {
            return word;
        } else {
            temp.insert(word);
        }
    }
    return "None";
}
