#include <iostream>

bool is_abundant(int n) {
    int fctrsum = 0;
    for (int fctr = 1; fctr < n; ++fctr) {
        if (n % fctr == 0) {
            fctrsum += fctr;
        }
    }
    return fctrsum > n;
}
