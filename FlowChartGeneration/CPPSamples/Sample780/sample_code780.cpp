#include <cmath>
#include <string>

std::string count_Divisors(int n) {
    int count = 0;
    for (int i = 1; i <= (int)(sqrt(n)) + 1; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count = count + 1;
            } else {
                count = count + 2;
            }
        }
    }
    if (count % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
