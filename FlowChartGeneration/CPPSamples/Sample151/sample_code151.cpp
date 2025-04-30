#include <vector>

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> c;
    while (!a.empty() && !b.empty()) {
        if (a[0] < b[0]) {
            c.push_back(a[0]);
            a.erase(a.begin());
        } else {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    if (a.empty()) {
        c.insert(c.end(), b.begin(), b.end());
    } else {
        c.insert(c.end(), a.begin(), a.end());
    }
    return c;
}

std::vector<int> merge_sort(std::vector<int> x) {
    if (x.size() == 0 || x.size() == 1) {
        return x;
    } else {
        size_t middle = x.size() / 2;
        std::vector<int> a = merge_sort(std::vector<int>(x.begin(), x.begin() + middle));
        std::vector<int> b = merge_sort(std::vector<int>(x.begin() + middle, x.end()));
        return merge(a, b);
    }
}
