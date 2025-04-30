#include <iostream>
using namespace std;

pair<double, double> circle_circumference(double r) {
    double perimeter = 2 * 3.1415 * r;
    return make_pair(perimeter, perimeter);
}
