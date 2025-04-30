#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int digits_sum(int n) {
    int neg = 1;
    if (n < 0) {
        n = -n;
        neg = -1;
    }
    std::string str_n = std::to_string(n);
    std::vector<int> digits;
    for (char c : str_n) {
        digits.push_back(c - '0');
    }
    digits[0] *= neg;
    return std::accumulate(digits.begin(), digits.end(), 0);
}

int count_nums(const std::vector<int>& arr) {
    return std::count_if(arr.begin(), arr.end(), [](int x) {
        return digits_sum(x) > 0;
    });
}
