#include <iostream>
using namespace std;

pair<int, int> count_no(int A, int N, int L, int R) {
    int count = 0;
    int i;
    for (i = L; i <= R; i++) {
        if (i % A != 0) {
            count++;
        }
        if (count == N) {
            break;
        }
    }
    return make_pair(i, count);
}
