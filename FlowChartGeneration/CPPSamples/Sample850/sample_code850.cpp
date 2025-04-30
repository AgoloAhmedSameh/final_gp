#include <iostream>
#include <cmath>

double Sum_of_Inverse_Divisors(int N, double Sum) {
    double ans = Sum / N;
    return round(ans * 100.0) / 100.0;
}
