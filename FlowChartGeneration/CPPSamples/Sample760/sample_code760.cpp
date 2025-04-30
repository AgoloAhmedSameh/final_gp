#include <iostream>
using namespace std;

pair<double, double> arc_length(double d, double a) {
    double pi = 22.0 / 7.0;
    if (a >= 360) {
        return {0.0, 0.0}; // Equivalent to returning None in Python
    }
    double arclength = (pi * d) * (a / 360);
    return {arclength, 0.0}; // Second value can be set to 0 or any other default
}
