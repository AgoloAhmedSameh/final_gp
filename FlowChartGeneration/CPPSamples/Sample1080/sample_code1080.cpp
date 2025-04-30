#include <iostream>
#include <vector>

std::vector<int> f(int n) {
    std::vector<int> ret;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            int x = 1;
            for (int j = 1; j <= i; ++j) x *= j;
            ret.push_back(x);
        } else {
            int x = 0;
            for (int j = 1; j <= i; ++j) x += j;
            ret.push_back(x);
        }
    }
    return ret;
}
