#include <string>

bool all_Characters_Same(const std::string& s) {
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] != s[0]) {
            return false;
        }
    }
    return true;
}
