#include <string>

int digitSum(const std::string& s) {
    if (s.empty()) return 0;
    int sum = 0;
    for (char char : s) {
        if (isupper(char)) {
            sum += static_cast<int>(char);
        }
    }
    return sum;
}
