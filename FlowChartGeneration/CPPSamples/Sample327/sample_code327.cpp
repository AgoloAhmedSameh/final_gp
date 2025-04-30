#include <vector>

std::vector<int> rotate_left(std::vector<int>& list1, int m, int n) {
    std::vector<int> result(list1.begin() + m, list1.end());
    result.insert(result.end(), list1.begin(), list1.begin() + n);
    return result;
}
