#include <vector>
#include <algorithm>

std::vector<int> get_odd_collatz(int n) {
    std::vector<int> odd_collatz;
    if (n % 2 == 1) {
        odd_collatz.push_back(n);
    }
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        
        if (n % 2 == 1) {
            odd_collatz.push_back(n);
        }
    }
    std::sort(odd_collatz.begin(), odd_collatz.end());
    return odd_collatz;
}
