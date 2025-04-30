#include <vector>

std::pair<int, int> Sum(int N) {
    std::vector<int> SumOfPrimeDivisors(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        if (SumOfPrimeDivisors[i] == 0) {
            for (int j = i; j <= N; j += i) {
                SumOfPrimeDivisors[j] += i;
            }
        }
    }
    return {SumOfPrimeDivisors[N], 0}; // Returning a pair, second value is placeholder
}
