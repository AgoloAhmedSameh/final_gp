#include <iostream>
using namespace std;

pair<int, int> odd_Days(int N) {
    int hund1 = N / 100;
    int hund4 = N / 400;
    int leap = N >> 2;
    int ordd = N - leap;
    if (hund1) {
        ordd += hund1;
        leap -= hund1;
    }
    if (hund4) {
        ordd -= hund4;
        leap += hund4;
    }
    int days = ordd + leap * 2;
    int odd = days % 7;
    return make_pair(odd, 0); // The second value is added as a placeholder
}
