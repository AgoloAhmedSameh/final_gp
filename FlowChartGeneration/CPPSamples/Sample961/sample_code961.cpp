#include <iostream>
using namespace std;

int sum_Natural(int n) { 
    int sum = (n * (n + 1)); 
    return sum; 
}

pair<int, int> sum_Even(int l, int r) { 
    return make_pair(sum_Natural(r / 2) - sum_Natural((l - 1) / 2), 0); 
}
