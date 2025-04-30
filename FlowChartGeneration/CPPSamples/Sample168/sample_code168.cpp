#include <iostream>
using namespace std;

pair<int, int> get_pell(int n) {
    if (n <= 2) {
        return {n, 0}; 
    }
    int a = 1;
    int b = 2;
    for (int i = 3; i <= n; ++i) {
        int c = 2 * b + a;
        a = b;
        b = c;
    }
    return {b, 0};
}
