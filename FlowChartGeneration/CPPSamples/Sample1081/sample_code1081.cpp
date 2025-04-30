#include <iostream>
#include <string>

std::pair<int, int> even_odd_palindrome(int n) {
    auto is_palindrome = [](int n) {
        std::string s = std::to_string(n);
        std::string reversed_s = std::string(s.rbegin(), s.rend());
        return s == reversed_s;
    };

    int even_palindrome_count = 0;
    int odd_palindrome_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1 && is_palindrome(i)) {
            odd_palindrome_count++;
        } else if (i % 2 == 0 && is_palindrome(i)) {
            even_palindrome_count++;
        }
    }
    return {even_palindrome_count, odd_palindrome_count};
}
