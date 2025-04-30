#include <vector>
#include <cmath>
#include <string>

int skjkasdkd(const std::vector<int>& lst) {
    auto isPrime = [](int n) {
        if (n < 2) return false;
        for (int i = 2; i <= std::sqrt(n); ++i) {
            if (n % i == 0) return false;
        }
        return true;
    };

    int maxx = 0;
    size_t i = 0;
    while (i < lst.size()) {
        if (lst[i] > maxx && isPrime(lst[i])) {
            maxx = lst[i];
        }
        i++;
    }

    int result = 0;
    for (char digit : std::to_string(maxx)) {
        result += digit - '0';
    }
    return result;
}
