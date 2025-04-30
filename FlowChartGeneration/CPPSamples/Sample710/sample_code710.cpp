#include <iostream>
using namespace std;

bool product_Equal(int n) {
    if (n < 10) {
        return false;
    }
    int prodOdd = 1, prodEven = 1;
    while (n > 0) {
        int digit = n % 10;
        prodOdd *= digit;
        n = n / 10;
        if (n == 0) {
            break;
        }
        digit = n % 10;
        prodEven *= digit;
        n = n / 10;
    }
    return prodOdd == prodEven;
}
