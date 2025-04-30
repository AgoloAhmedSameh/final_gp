#include <string>

int vowels_count(const std::string& s) {
    std::string vowels = "aeiouAEIOU";
    int n_vowels = 0;

    for (char c : s) {
        if (vowels.find(c) != std::string::npos) {
            n_vowels++;
        }
    }

    if (!s.empty() && (s.back() == 'y' || s.back() == 'Y')) {
        n_vowels++;
    }

    return n_vowels;
}
