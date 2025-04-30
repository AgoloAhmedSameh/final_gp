#include <vector>

int fib4(int n) {
    std::vector<int> results = {0, 0, 2, 0};
    if (n < 4) {
        return results[n];
    }

    for (int i = 4; i <= n; ++i) {
        results.push_back(results[results.size() - 1] + results[results.size() - 2] + results[results.size() - 3] + results[results.size() - 4]);
        results.erase(results.begin());
    }

    return results.back();
}
