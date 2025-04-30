#include <algorithm>
#include <string>

std::string intersection(std::pair<int, int> interval1, std::pair<int, int> interval2) {
    auto is_prime = [](int num) {
        if (num == 1 || num == 0) return false;
        if (num == 2) return true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    };

    int l = std::max(interval1.first, interval2.first);
    int r = std::min(interval1.second, interval2.second);
    int length = r - l;
    if (length > 0 && is_prime(length)) {
        return "YES";
    }
    return "NO";
}
