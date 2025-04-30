#include <string>

std::pair<std::string, std::string> reverse_vowels(const std::string& str1) {
    std::string vowels = "";
    for (char char : str1) {
        if (char == 'a' || char == 'e' || char == 'i' || char == 'o' || char == 'u' || 
            char == 'A' || char == 'E' || char == 'I' || char == 'O' || char == 'U') {
            vowels += char;
        }
    }
    std::string result_string = "";
    for (char char : str1) {
        if (char == 'a' || char == 'e' || char == 'i' || char == 'o' || char == 'u' || 
            char == 'A' || char == 'E' || char == 'I' || char == 'O' || char == 'U') {
            result_string += vowels.back();
            vowels.pop_back();
        } else {
            result_string += char;
        }
    }
    return {result_string, ""}; // The second string is not used in the original code
}
