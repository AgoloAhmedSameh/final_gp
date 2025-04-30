#include <iostream>
using namespace std;

pair<int, int> count_Set_Bits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return make_pair(count, 0);
}
