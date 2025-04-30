#include <string>
#include <vector>
#include <sstream>

bool is_Word_Present(const std::string& sentence, const std::string& word) {
    std::istringstream iss(sentence);
    std::string token;
    while (iss >> token) {
        if (token == word) {
            return true;
        }
    }
    return false;
}
