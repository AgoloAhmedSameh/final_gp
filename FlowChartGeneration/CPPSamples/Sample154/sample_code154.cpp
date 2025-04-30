#include <iostream>
using namespace std;

pair<int, int> even_bit_toggle_number(int n) {
    int res = 0, count = 0, temp = n;
    while (temp > 0) {
        if (count % 2 == 1) {
            res = res | (1 << count);
        }
        count = count + 1;
        temp >>= 1;
    }
    return make_pair(n ^ res, res);
}
