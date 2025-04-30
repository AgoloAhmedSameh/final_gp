#include <vector>

std::pair<int, int> count_tuplex(const std::vector<int>& tuplex, int value) {
    int count = std::count(tuplex.begin(), tuplex.end(), value);
    return {count, count};
}
