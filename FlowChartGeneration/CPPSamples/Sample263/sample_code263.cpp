#include <iostream>
using namespace std;

pair<double, double> dog_age(double h_age) {
    if (h_age < 0) {
        exit(0);
    } else if (h_age <= 2) {
        double d_age = h_age * 10.5;
        return make_pair(d_age, 0);
    } else {
        double d_age = 21 + (h_age - 2) * 4;
        return make_pair(d_age, 0);
    }
}
