#include <cmath>

std::pair<int, int> fourth_Power_Sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum = sum + (i * i * i * i);
    }
    return {sum, sum}; // Assuming you want to return the same sum twice as a pair
}
