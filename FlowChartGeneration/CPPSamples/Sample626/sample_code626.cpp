#include <vector>

int find_First_Missing(std::vector<int>& array, int start, int end) {
    if (start > end) {
        return end + 1;
    }
    if (start != array[start]) {
        return start;
    }
    int mid = (start + end) / 2;
    if (array[mid] == mid) {
        return find_First_Missing(array, mid + 1, end);
    }
    return find_First_Missing(array, start, mid);
}
