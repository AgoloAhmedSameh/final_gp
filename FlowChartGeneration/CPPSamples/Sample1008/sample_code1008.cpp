#include <vector>
#include <set>
#include <algorithm>

std::vector<int> unique(const std::vector<int>& l) {
    std::set<int> s(l.begin(), l.end());
    std::vector<int> result(s.begin(), s.end());
    std::sort(result.begin(), result.end());
    return result;
}
