#include <iostream>
#include <string>
#include <utility>

std::pair<std::pair<int, int>, std::pair<int, int>> dig_let(const std::string &s) {
    int d = 0, l = 0;
    for (char c : s) {
        if (isdigit(c)) {
            d++;
        } else if (isalpha(c)) {
            l++;
        } else {
            continue;
        }
    }
    return {{l, d}};
}
