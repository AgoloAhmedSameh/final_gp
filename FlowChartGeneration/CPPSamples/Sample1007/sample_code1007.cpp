#include <vector>
#include <algorithm>

std::vector<int> sort_third(std::vector<int> l) {
    std::vector<int> temp;
    for (size_t i = 0; i < l.size(); i += 3) {
        temp.push_back(l[i]);
    }
    std::sort(temp.begin(), temp.end());
    for (size_t i = 0, j = 0; i < l.size(); i += 3, ++j) {
        l[i] = temp[j];
    }
    return l;
}
