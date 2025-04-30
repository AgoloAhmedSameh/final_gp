#include <string>

std::string Check_Solution(int a, int b, int c) {
    if (2 * b * b == 9 * a * c) {
        return "Yes";
    } else {
        return "No";
    }
}
