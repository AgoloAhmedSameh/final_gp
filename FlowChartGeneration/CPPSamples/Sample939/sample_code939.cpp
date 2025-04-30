#include <vector>
#include <algorithm>

void shift_down(std::vector<int>& arr, int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) {
        int child = root * 2 + 1;
        if (child + 1 <= end && arr[child] < arr[child + 1]) {
            child += 1;
        }
        if (child <= end && arr[root] < arr[child]) {
            std::swap(arr[root], arr[child]);
            root = child;
        } else {
            return;
        }
    }
}

void heapify(std::vector<int>& arr) {
    int start = arr.size() / 2;
    while (start >= 0) {
        shift_down(arr, start, arr.size() - 1);
        start -= 1;
    }
}

std::vector<int> heap_sort(std::vector<int>& arr) {
    heapify(arr);
    int end = arr.size() - 1;
    while (end > 0) {
        std::swap(arr[end], arr[0]);
        shift_down(arr, 0, end - 1);
        end -= 1;
    }
    return arr;
}
