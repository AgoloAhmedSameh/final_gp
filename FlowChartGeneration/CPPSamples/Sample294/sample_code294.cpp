#include <vector>
#include <numeric>

std::pair<int, int> sum_div(int number) {
    std::vector<int> divisors = {1};
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            divisors.push_back(i);
        }
    }
    return {std::accumulate(divisors.begin(), divisors.end(), 0), 0};
}
