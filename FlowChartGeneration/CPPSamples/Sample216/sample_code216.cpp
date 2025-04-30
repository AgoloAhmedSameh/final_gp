#include <unordered_map>
#include <string>

char first_Repeated_Char(const std::string& str) {
    std::unordered_map<char, int> h;
    for (char ch : str) {
        if (h.find(ch) != h.end()) {
            return ch;
        } else {
            h[ch] = 0;
        }
    }
    return '\0';
}
