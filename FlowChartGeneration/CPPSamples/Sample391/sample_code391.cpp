#include <vector>
#include <algorithm>

std::pair<int, int> get_max_sum(int n) {
    std::vector<int> res;
    res.push_back(0);
    res.push_back(1);
    int i = 2;
    while (i < n + 1) {
        res.push_back(std::max(i, res[i / 2] + res[i / 3] + res[i / 4] + res[i / 5]));
        i = i + 1;
    }
    return {res[n]};
}
