#include <iostream>
#include <cmath>

std::pair<int, int> first_Digit(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact = fact * i;
        while (fact % 10 == 0) {
            fact = fact / 10;
        }
    }
    while (fact >= 10) {
        fact = fact / 10;
    }
    return std::make_pair(static_cast<int>(fact), static_cast<int>(std::floor(fact)));
}
