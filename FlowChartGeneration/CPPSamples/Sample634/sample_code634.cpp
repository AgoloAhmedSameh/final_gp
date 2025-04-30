#include <vector>
#include <queue>

std::vector<int> heap_sort(const std::vector<int>& iterable) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> h;
    for (int value : iterable) {
        h.push(value);
    }
    std::vector<int> sorted;
    while (!h.empty()) {
        sorted.push_back(h.top());
        h.pop();
    }
    return sorted;
}
