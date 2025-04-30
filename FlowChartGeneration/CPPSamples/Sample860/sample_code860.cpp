#include <vector>
#include <string>
#include <algorithm>
#include <map>

std::vector<std::string> anagram_lambda(const std::vector<std::string>& texts, const std::string& str) {
    std::map<char, int> countStr;
    for (char c : str) {
        countStr[c]++;
    }

    std::vector<std::string> result;
    for (const std::string& x : texts) {
        std::map<char, int> countX;
        for (char c : x) {
            countX[c]++;
        }
        if (countStr == countX) {
            result.push_back(x);
        }
    }
    return result;
}
