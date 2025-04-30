#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int min_coins(vector<int>& coins, int m, int V) {
    if (V == 0) {
        return 0;
    }
    int res = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (coins[i] <= V) {
            int sub_res = min_coins(coins, m, V - coins[i]);
            if (sub_res != INT_MAX && sub_res + 1 < res) {
                res = sub_res + 1;
            }
        }
    }
    return res;
}
