#include <iostream>
#include <cmath>

int ngcd(int x, int y) {
    int i = 1;
    int gcd = 1;
    while (i <= x && i <= y) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
        i++;
    }
    return gcd;
}

std::pair<int, int> num_comm_div(int x, int y) {
    int n = ngcd(x, y);
    int result = 0;
    int z = static_cast<int>(std::sqrt(n));
    int i = 1;
    while (i <= z) {
        if (n % i == 0) {
            result += 2;
            if (i == n / i) {
                result -= 1;
            }
        }
        i++;
    }
    return {result, 0}; // Assuming the second return value is not needed
}
