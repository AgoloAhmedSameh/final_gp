#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 3000;

std::pair<int, std::vector<int>> smartNumber(int n) {
    std::vector<int> primes(MAX, 0);
    std::vector<int> result;

    for (int i = 2; i < MAX; i++) {
        if (primes[i] == 0) {
            primes[i] = 1;
            for (int j = i * 2; j < MAX; j += i) {
                primes[j]--;
                if ((primes[j] + 3) == 0) {
                    result.push_back(j);
                }
            }
        }
    }
    
    std::sort(result.begin(), result.end());
    return {result[n - 1], result};
}

int main() {
    int n; // Input value for n
    std::cin >> n;
    auto result = smartNumber(n);
    std::cout << result.first << std::endl;
    return 0;
}
