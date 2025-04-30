#include <vector>
#include <map>

std::vector<int> count_variable(int a, int b, int c, int d) {
    std::map<int, int> counter;
    counter[a]++;
    counter[b]++;
    counter[c]++;
    counter[d]++;

    std::vector<int> elements;
    for (const auto& pair : counter) {
        for (int i = 0; i < pair.second; ++i) {
            elements.push_back(pair.first);
        }
    }
    
    return elements;
}
