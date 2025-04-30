#include <vector>
#include <unordered_map>

std::pair<std::vector<std::unordered_map<int, int>>, std::vector<std::unordered_map<int, int>>> empty_list(int length) {
    std::vector<std::unordered_map<int, int>> emptyList(length);
    return { emptyList, emptyList };
}
