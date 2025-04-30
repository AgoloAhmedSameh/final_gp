#include <string>

bool correct_bracketing(const std::string& brackets) {
    int depth = 0;
    for (char b : brackets) {
        if (b == '(') {
            depth += 1;
        } else {
            depth -= 1;
        }
        if (depth < 0) {
            return false;
        }
    }
    return depth == 0;
}
