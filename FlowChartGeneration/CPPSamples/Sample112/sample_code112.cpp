#include <string>
#include <cctype>

bool check_integer(const std::string& text) {
    std::string trimmed_text = text;
    trimmed_text.erase(0, trimmed_text.find_first_not_of(" \t\n"));
    trimmed_text.erase(trimmed_text.find_last_not_of(" \t\n") + 1);
    
    if (trimmed_text.length() < 1) {
        return false; // Returning false instead of None
    } else {
        if (all_of(trimmed_text.begin(), trimmed_text.end(), ::isdigit)) {
            return true;
        } else if ((trimmed_text[0] == '+' || trimmed_text[0] == '-') &&
                   all_of(trimmed_text.begin() + 1, trimmed_text.end(), ::isdigit)) {
            return true;
        } else {
            return false;
        }
    }
}
