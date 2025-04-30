#include <string>
#include <unordered_set>

std::string get_closest_vowel(const std::string& word) {
    if (word.length() < 3) {
        return "";
    }

    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'O', 'U', 'I'};
    for (int i = word.length() - 2; i > 0; --i) {
        if (vowels.find(word[i]) != vowels.end()) {
            if (vowels.find(word[i + 1]) == vowels.end() && vowels.find(word[i - 1]) == vowels.end()) {
                return std::string(1, word[i]);
            }
        }
    }
    return "";
}
