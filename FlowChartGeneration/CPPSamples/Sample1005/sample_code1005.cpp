#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int k = 2; k < n - 1; k++) {
        if (n % k == 0) {
            return false;
        }
    }
    return true;
}
