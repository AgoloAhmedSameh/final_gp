#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> lucky_num(int n) {
    std::vector<int> List;
    for (int i = -1; i <= n*n + 8; i += 2) {
        List.push_back(i);
    }
    int i = 2;
    while (i < List.size()) {
        std::set<int> tmp_set(List.begin(), List.end());
        for (int j = i; j < List.size(); j += List[i]) {
            tmp_set.erase(List[j]);
        }
        List.assign(tmp_set.begin(), tmp_set.end());
        std::sort(List.begin(), List.end());
        i++;
    }
    std::vector<int> result(List.begin() + 1, List.begin() + n + 1);
    return {result, {}};
}
