#include <iostream>
using namespace std;

int newman_prime(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return 2 * newman_prime(n - 1) + newman_prime(n - 2);
}
