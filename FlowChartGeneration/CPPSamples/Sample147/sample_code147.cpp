#include <iostream>
using namespace std;

int sum_digits_single(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int closest(int x) {
    int ans = 0;
    while (ans * 10 + 9 <= x) {
        ans = ans * 10 + 9;
    }
    return ans;
}

pair<int, int> sum_digits_twoparts(int N) {
    int A = closest(N);
    return make_pair(sum_digits_single(A) + sum_digits_single(N - A), 0);
}
