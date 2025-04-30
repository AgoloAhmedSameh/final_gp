#include <iostream>
using namespace std;

int next_Power_Of_2(int n) {
    int count = 0;
    if (n && !(n & (n - 1))) {
        return n;
    }
    while (n != 0) {
        n >>= 1;
        count++;
    }
    return 1 << count;
}
