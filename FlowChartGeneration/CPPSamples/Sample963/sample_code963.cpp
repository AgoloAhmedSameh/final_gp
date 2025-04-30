#include <string>
#include <sstream>
#include <vector>

bool word_len(const std::string& s) { 
    std::istringstream iss(s); 
    std::string word; 
    while (iss >> word) { 
        if (word.length() % 2 == 0) 
            return true; 
        else 
            return false; 
    } 
    return false; 
}
