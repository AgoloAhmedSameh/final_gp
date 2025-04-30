#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> heap_replace(std::vector<int>& heap, int a) {
    std::make_heap(heap.begin(), heap.end());
    std::pop_heap(heap.begin(), heap.end());
    heap.back() = a;
    std::push_heap(heap.begin(), heap.end());
    return {heap, {}};
}
