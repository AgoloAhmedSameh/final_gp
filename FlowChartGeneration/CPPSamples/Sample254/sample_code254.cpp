#include <vector>
#include <tuple>

std::vector<std::vector<int>> combinations_colors(const std::vector<int>& l, int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    
    std::function<void(int, int)> backtrack = [&](int start, int remaining) {
        if (remaining == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < l.size(); ++i) {
            combination.push_back(l[i]);
            backtrack(i, remaining - 1);
            combination.pop_back();
        }
    };
    
    backtrack(0, n);
    return result;
}
