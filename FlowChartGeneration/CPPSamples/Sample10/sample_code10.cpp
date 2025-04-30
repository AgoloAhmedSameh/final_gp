#include <string>

std::pair<std::string, std::string> remove_Occ(std::string s, char ch) {
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            s = s.substr(0, i) + s.substr(i + 1);
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ch) {
            s = s.substr(0, i) + s.substr(i + 1);
            break;
        }
    }
    return {s, ""};
}
