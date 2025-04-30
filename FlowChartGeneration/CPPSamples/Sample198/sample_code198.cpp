#include <iostream>
using namespace std;

int highest_Power_of_2(int n) {
    int res = 0;
    for (int i = n; i > 0; --i) {
        if ((i & (i - 1)) == 0) {
            res = i;
            break;
        }
    }
    return res;
}
