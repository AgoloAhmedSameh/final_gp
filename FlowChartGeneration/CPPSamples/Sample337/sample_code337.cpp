#include <string>

bool check_Equality(const std::string& s) {
    return (s[0] == s[s.length() - 1]);
}

int count_Substring_With_Equal_Ends(const std::string& s) {
    int result = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            if (check_Equality(s.substr(i, j))) {
                result++;
            }
        }
    }
    return result;
}
