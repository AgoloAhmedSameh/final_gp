#include <string>

std::pair<int, int> last_occurrence_char(const std::string& str, char ch) {
    int flag = -1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            flag = i;
        }
    }
    if (flag == -1) {
        return {-1, -1}; // Returning -1, -1 to indicate None
    } else {
        return {flag + 1, 0}; // Returning the position + 1 and a second value (0 for consistency)
    }
}
