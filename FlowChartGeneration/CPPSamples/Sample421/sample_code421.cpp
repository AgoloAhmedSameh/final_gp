#include <iostream>
#include <cmath>

std::pair<double, double> find_Average_Of_Cube(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    return std::make_pair(round(sum / n * 1000000) / 1000000, 0); // Round to 6 decimal places
}
