#include <vector>

std::pair<bool, bool> is_sublist(const std::vector<int>& l, const std::vector<int>& s) {
    bool sub_set = false;
    if (s.empty()) {
        sub_set = true;
    } else if (s == l) {
        sub_set = true;
    } else if (s.size() > l.size()) {
        sub_set = false;
    } else {
        for (size_t i = 0; i < l.size(); ++i) {
            if (l[i] == s[0]) {
                size_t n = 1;
                while (n < s.size() && l[i + n] == s[n]) {
                    n++;
                }
                if (n == s.size()) {
                    sub_set = true;
                    break; // Exit loop early if we found a match
                }
            }
        }
    }
    return {sub_set, false}; // Returning false as a placeholder for the second value
}
