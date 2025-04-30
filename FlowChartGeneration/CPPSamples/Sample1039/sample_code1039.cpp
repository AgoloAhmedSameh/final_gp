#include <string>
#include <algorithm>

std::string circular_shift(int x, int shift) {
    std::string s = std::to_string(x);
    if (shift > s.length()) {
        std::reverse(s.begin(), s.end());
        return s;
    } else {
        return s.substr(s.length() - shift) + s.substr(0, s.length() - shift);
    }
}
