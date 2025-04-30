#include <vector>
#include <algorithm>

std::pair<std::vector<std::vector<int>>, std::vector<int>> colon_tuplex(std::vector<std::vector<int>> tuplex, int m, int n) {
    std::vector<std::vector<int>> tuplex_colon = tuplex;
    tuplex_colon[m].push_back(n);
    return {tuplex_colon, tuplex_colon[m]};
}
