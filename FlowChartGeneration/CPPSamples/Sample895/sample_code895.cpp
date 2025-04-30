#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

auto last(const tuple<int, int>& n) {
    return get<1>(n);
}

vector<tuple<int, int>> sort_list_last(vector<tuple<int, int>>& tuples) {
    sort(tuples.begin(), tuples.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
        return last(a) < last(b);
    });
    return tuples;
}
