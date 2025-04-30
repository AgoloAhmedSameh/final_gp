#include <string>

bool prime_length(const std::string& str) {
    int l = str.length();
    if (l == 0 || l == 1) {
        return false;
    }
    for (int i = 2; i < l; i++) {
        if (l % i == 0) {
            return false;
        }
    }
    return true;
}
