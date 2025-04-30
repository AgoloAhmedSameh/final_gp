#include <iostream>
#include <string>

int find_Rotations(const std::string& str) {
    std::string tmp = str + str;
    int n = str.length();
    for (int i = 1; i <= n; ++i) {
        std::string substring = tmp.substr(i, n);
        if (str == substring) {
            return i;
        }
    }
    return n;
}
