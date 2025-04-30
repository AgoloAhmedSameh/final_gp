#include <cmath>
#include <utility>

std::pair<int, int> sumofFactors(int n) {
    if (n % 2 != 0) {
        return {0, 0};
    }
    int res = 1;
    for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i) {
        int count = 0;
        int curr_sum = 1;
        int curr_term = 1;
        while (n % i == 0) {
            count = count + 1;
            n = n / i;
            if (i == 2 && count == 1) {
                curr_sum = 0;
            }
            curr_term = curr_term * i;
            curr_sum = curr_sum + curr_term;
        }
        res = res * curr_sum;
    }
    if (n >= 2) {
        res = res * (1 + n);
    }
    return {res, 0};
}
