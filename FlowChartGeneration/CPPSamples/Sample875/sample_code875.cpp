#include <iostream>
using namespace std;

pair<int, int> lcm(int x, int y) {
    int z;
    if (x > y) {
        z = x;
    } else {
        z = y;
    }
    while (true) {
        if ((z % x == 0) && (z % y == 0)) {
            return make_pair(z, z);
        }
        z += 1;
    }
}
