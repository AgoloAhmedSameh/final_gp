#include <vector>
#include <string>

std::string match_parens(const std::vector<std::string>& lst) {
    auto check = [](const std::string& s) {
        int val = 0;
        for (char i : s) {
            if (i == '(') {
                val += 1;
            } else {
                val -= 1;
            }
            if (val < 0) {
                return false;
            }
        }
        return val == 0;
    };

    std::string S1 = lst[0] + lst[1];
    std::string S2 = lst[1] + lst[0];
    return check(S1) || check(S2) ? "Yes" : "No";
}
