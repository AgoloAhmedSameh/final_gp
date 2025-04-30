#include <iostream>
#include <string>
#include <sstream>

std::string string_sequence(int n) {
    std::ostringstream result;
    for (int x = 0; x <= n; ++x) {
        result << x;
        if (x < n) {
            result << ' ';
        }
    }
    return result.str();
}
