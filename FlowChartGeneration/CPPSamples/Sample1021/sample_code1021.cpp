#include <vector>
#include <algorithm>

double median(std::vector<int>& l) {
    std::sort(l.begin(), l.end());
    if (l.size() % 2 == 1) {
        return l[l.size() / 2];
    } else {
        return (l[l.size() / 2 - 1] + l[l.size() / 2]) / 2.0;
    }
}
