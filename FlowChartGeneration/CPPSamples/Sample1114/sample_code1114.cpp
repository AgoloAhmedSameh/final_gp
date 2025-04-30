#include <string>

std::string fix_spaces(const std::string& text) {
    std::string new_text = "";
    size_t i = 0;
    size_t start = 0, end = 0;
    
    while (i < text.length()) {
        if (text[i] == ' ') {
            end++;
        } else {
            if (end - start > 2) {
                new_text += "-" + std::string(1, text[i]);
            } else if (end - start > 0) {
                new_text += std::string(end - start, '_') + text[i];
            } else {
                new_text += text[i];
            }
            start = i + 1;
            end = i + 1;
        }
        i++;
    }
    
    if (end - start > 2) {
        new_text += "-";
    } else if (end - start > 0) {
        new_text += "_";
    }
    
    return new_text;
}
