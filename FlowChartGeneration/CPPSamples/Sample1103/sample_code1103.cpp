#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> minPath(std::vector<std::vector<int>>& grid, int k) {
    int n = grid.size();
    int val = n * n + 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                std::vector<int> temp;
                if (i != 0) {
                    temp.push_back(grid[i - 1][j]);
                }
                if (j != 0) {
                    temp.push_back(grid[i][j - 1]);
                }
                if (i != n - 1) {
                    temp.push_back(grid[i + 1][j]);
                }
                if (j != n - 1) {
                    temp.push_back(grid[i][j + 1]);
                }
                if (!temp.empty()) {
                    val = *std::min_element(temp.begin(), temp.end());
                }
            }
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < k; ++i) {
        if (i % 2 == 0) {
            ans.push_back(1);
        } else {
            ans.push_back(val);
        }
    }
    return ans;
}
