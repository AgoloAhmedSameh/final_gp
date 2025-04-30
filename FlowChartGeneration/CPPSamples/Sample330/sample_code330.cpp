#include <iostream>
using namespace std;

pair<int, int> count_unset_bits(int n) { 
    int count = 0; 
    int x = 1; 
    while (x < n + 1) { 
        if ((x & n) == 0) { 
            count += 1; 
        } 
        x = x << 1; 
    } 
    return make_pair(count, 0);
}
