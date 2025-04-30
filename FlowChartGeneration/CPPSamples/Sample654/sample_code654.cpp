#include <iostream>
using namespace std;

pair<int, int> fifth_Power_Sum(int n) {
    int sm = 0;
    for (int i = 1; i <= n; ++i) {
        sm += (i * i * i * i * i);
    }
    return make_pair(sm, 0); // Returning 0 as a placeholder for the second value
}
