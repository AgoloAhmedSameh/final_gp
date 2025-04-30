#include <vector>
#include <string>

std::vector<int> divisible_by_digits(int startnum, int endnum) {
    std::vector<int> result;
    for (int n = startnum; n <= endnum; ++n) {
        std::string str_n = std::to_string(n);
        bool divisible = true;
        for (char x : str_n) {
            int digit = x - '0';
            if (digit == 0 || n % digit != 0) {
                divisible = false;
                break;
            }
        }
        if (divisible) {
            result.push_back(n);
        }
    }
    return result;
}
