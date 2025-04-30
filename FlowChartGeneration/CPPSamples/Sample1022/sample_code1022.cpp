#include <string>

bool is_palindrome(const std::string& text) {
    for (size_t i = 0; i < text.length(); ++i) {
        if (text[i] != text[text.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}
