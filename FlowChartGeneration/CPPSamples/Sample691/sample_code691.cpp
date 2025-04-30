#include <iostream>
using namespace std;

pair<int, int> last_Two_Digits(int N) {
    if (N >= 10) {
        return {0, 0};
    }
    int fac = 1;
    for (int i = 1; i <= N; i++) {
        fac = (fac * i) % 100;
    }
    return {fac, 0};
}
