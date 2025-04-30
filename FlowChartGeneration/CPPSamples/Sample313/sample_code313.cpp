#include <algorithm>
#include <vector>

std::pair<int, int> max_sum_rectangular_grid(const std::vector<std::vector<int>>& grid, int n) {
    int incl = std::max(grid[0][0], grid[1][0]);
    int excl = 0;
    for (int i = 1; i < n; ++i) {
        int excl_new = std::max(excl, incl);
        incl = excl + std::max(grid[0][i], grid[1][i]);
        excl = excl_new;
    }
    return std::make_pair(std::max(excl, incl), 0);
}
