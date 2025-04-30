#include <iostream>
using namespace std;

int sum_series(int n) {
    if (n < 1) {
        return 0;
    } else {
        return n + sum_series(n - 2);
    }
}
