#include <vector>
#include <string>
#include <numeric>

std::pair<int, int> multiple_to_single(const std::vector<int>& L) {
    std::string str = std::accumulate(L.begin(), L.end(), std::string(), [](std::string a, int b) {
        return a + std::to_string(b);
    });
    int x = std::stoi(str);
    return {x, x}; // Assuming you want to return x twice as the original function returns a tuple
}
