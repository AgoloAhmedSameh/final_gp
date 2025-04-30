#include <iostream>
using namespace std;

int sum_Odd(int n) { 
    int terms = (n + 1) / 2; 
    int sum1 = terms * terms; 
    return sum1; 
}

pair<int, int> sum_in_Range(int l, int r) { 
    return {sum_Odd(r) - sum_Odd(l - 1)};
}
