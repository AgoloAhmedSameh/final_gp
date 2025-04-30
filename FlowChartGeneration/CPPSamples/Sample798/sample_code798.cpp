#include <iostream>
using namespace std;

const int INT_BITS = 32;

unsigned int left_Rotate(unsigned int n, unsigned int d) {
    return (n << d) | (n >> (INT_BITS - d));
}
