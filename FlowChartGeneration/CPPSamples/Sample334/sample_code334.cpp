#include <iostream>
using namespace std;

pair<double, double> ap_sum(double a, int n, double d) {
    double total = (n * (2 * a + (n - 1) * d)) / 2;
    return make_pair(total, total);
}
