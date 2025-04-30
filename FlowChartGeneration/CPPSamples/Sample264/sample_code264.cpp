#include <vector>
#include <string>

std::pair<std::vector<std::vector<char>>, std::vector<std::vector<char>>> list_split(const std::string& S, int step) {
    std::vector<std::vector<char>> result(step);
    for (int i = 0; i < step; ++i) {
        for (size_t j = i; j < S.size(); j += step) {
            result[i].push_back(S[j]);
        }
    }
    return {result, {}};
}
