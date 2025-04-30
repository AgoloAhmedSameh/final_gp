#include <iostream>
using namespace std;

pair<int, int> Total_Hamming_Distance(int n) {
    int i = 1;
    int sum = 0;
    while (n / i > 0) {
        sum = sum + n / i;
        i = i * 2;
    }
    return make_pair(sum, 0); // Note: Returning 0 as a placeholder for the second value
}
