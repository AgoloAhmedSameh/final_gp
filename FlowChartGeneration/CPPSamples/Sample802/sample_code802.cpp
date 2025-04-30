#include <iostream>
using namespace std;

bool is_Perfect_Square(int n) {
    int i = 1;
    while (i * i <= n) {
        if ((n % i == 0) && (n / i == i)) {
            return true;     
        }
        i = i + 1;
    }
    return false;
}
