#include <algorithm>
using namespace std;

pair<int, int> min_Jumps(int a, int b, int d) {
    int temp = a;
    a = min(a, b);
    b = max(temp, b);
    if (d >= b) {
        return (d + b - 1) / b;
    }
    if (d == 0) {
        return 0;
    }
    if (d == a) {
        return 1;
    } else {
        return 2;
    }
}
