#include <cmath>

int get_sum(int n) {
    int sum = 0;
    int i = 1;
    while (i <= std::sqrt(n)) {
        if (n % i == 0) {
            if (n / i == i) {
                sum += i;
            } else {
                sum += i;
                sum += (n / i);
            }
        }
        i++;
    }
    sum -= n;
    return sum;
}

bool check_abundant(int n) {
    return get_sum(n) > n;
}
