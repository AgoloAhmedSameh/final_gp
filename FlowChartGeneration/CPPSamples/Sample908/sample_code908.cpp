#include <iostream>
#include <string>

std::pair<int, int> previous_palindrome(int num) {
    for (int x = num - 1; x > 0; --x) {
        std::string str_x = std::to_string(x);
        std::string rev_str_x = std::string(str_x.rbegin(), str_x.rend());
        if (str_x == rev_str_x) {
            return {x, 0}; // Assuming we want to match the return type
        }
    }
    return {0, 0}; // If no palindrome is found
}
