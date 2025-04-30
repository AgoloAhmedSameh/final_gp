#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

std::string rearrange_string(const std::string& S) {
    std::unordered_map<char, int> ctr;
    for (char c : S) {
        ctr[c]++;
    }

    std::priority_queue<std::pair<int, char>> heap;
    for (const auto& entry : ctr) {
        heap.push({-entry.second, entry.first});
    }

    if (-heap.top().first * 2 > S.size() + 1) {
        return "";
    }

    std::string ans;
    while (heap.size() >= 2) {
        auto [nct1, char1] = heap.top(); heap.pop();
        auto [nct2, char2] = heap.top(); heap.pop();
        ans.push_back(char1);
        ans.push_back(char2);
        if (nct1 + 1) heap.push({nct1 + 1, char1});
        if (nct2 + 1) heap.push({nct2 + 1, char2});
    }

    if (!heap.empty()) {
        ans.push_back(heap.top().second);
    }

    return ans;
}
