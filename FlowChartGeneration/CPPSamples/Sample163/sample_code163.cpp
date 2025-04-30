#include <iostream>
#include <cmath>

int divSum(int n) {
    int sum = 1;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            sum = sum + i + std::floor(n / i);
        }
        i += 1;
    }
    return sum;
}

bool areEquivalent(int num1, int num2) {
    return divSum(num1) == divSum(num2);
}
