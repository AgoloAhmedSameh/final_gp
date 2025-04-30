#include <iostream>
#include <string>

long long next_smallest_palindrome(long long num) {
    for (long long i = num + 1; i < LLONG_MAX; ++i) {
        std::string numstr = std::to_string(i);
        std::string revstr = std::string(numstr.rbegin(), numstr.rend());
        if (numstr == revstr) {
            return i;
        }
    }
    return -1; // In case there's no palindrome found (theoretically it should never reach here)
}
