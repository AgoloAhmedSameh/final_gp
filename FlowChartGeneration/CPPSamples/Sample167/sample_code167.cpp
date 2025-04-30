#include <vector>

std::pair<int, int> frequency(const std::vector<int>& a, int x) {
    int count = 0;
    for (int i : a) {
        if (i == x) count++;
    }
    return {count, 0}; // Return 0 as the second value to match the function signature
}
