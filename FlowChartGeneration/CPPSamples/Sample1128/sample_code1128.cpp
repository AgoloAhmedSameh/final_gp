#include <string>

bool cycpattern_check(const std::string& a, const std::string& b) {
    int l = b.length();
    std::string pat = b + b;
    for (int i = 0; i <= a.length() - l; i++) {
        for (int j = 0; j <= l; j++) {
            if (a.substr(i, l) == pat.substr(j, l)) {
                return true;
            }
        }
    }
    return false;
}
