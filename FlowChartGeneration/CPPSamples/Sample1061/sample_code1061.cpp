#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> get_row(const std::vector<std::vector<int>>& lst, int x) {
    std::vector<std::pair<int, int>> coords;
    for (int i = 0; i < lst.size(); ++i) {
        for (int j = 0; j < lst[i].size(); ++j) {
            if (lst[i][j] == x) {
                coords.emplace_back(i, j);
            }
        }
    }
    std::sort(coords.begin(), coords.end(), [](const auto& a, const auto& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });
    return coords;
}
