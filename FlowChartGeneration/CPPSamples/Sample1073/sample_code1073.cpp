#include <iostream>
#include <string>
#include <cmath>

int closest_integer(const std::string& value) {
    std::string str = value;

    if (std::count(str.begin(), str.end(), '.') == 1) {
        // remove trailing zeros
        while (!str.empty() && str.back() == '0') {
            str.pop_back();
        }
        if (!str.empty() && str.back() == '.') {
            str.pop_back();
        }
    }

    double num = std::stod(str);
    int res;

    if (str.size() >= 2 && str.substr(str.size() - 2) == ".5") {
        if (num > 0) {
            res = std::ceil(num);
        } else {
            res = std::floor(num);
        }
    } else if (str.size() > 0) {
        res = static_cast<int>(std::round(num));
    } else {
        res = 0;
    }

    return res;
}
