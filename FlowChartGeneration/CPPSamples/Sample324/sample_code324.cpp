#include <iostream>
#include <algorithm>
using namespace std;

int get_Min_Squares(int n) {
    if (n <= 3) {
        return n;
    }
    int res = n;
    for (int x = 1; x <= n; x++) {
        int temp = x * x;
        if (temp > n) {
            break;
        } else {
            res = min(res, 1 + get_Min_Squares(n - temp));
        }
    }
    return res;
}
