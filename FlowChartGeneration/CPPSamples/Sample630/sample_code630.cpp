#include <iostream>
#include <string>
#include <algorithm>

std::string replace_spaces(std::string text) {
    std::replace(text.begin(), text.end(), ' ', '_');
    return text;
}

int main() {
    std::string text = "Python Exercises";
    std::string modified_text = replace_spaces(text);
    std::cout << modified_text << std::endl;
    return 0;
}
