#include <iostream>
using namespace std;

pair<long long, long long> odd_Num_Sum(int n) {
    long long j = 0;
    long long sm = 0;
    for (int i = 1; i <= n; ++i) {
        j = (2 * i - 1);
        sm = sm + (j * j * j * j * j);
    }
    return make_pair(sm, 0);
}
