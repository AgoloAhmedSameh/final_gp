#include <vector>
#include <algorithm>

class Pair {
public:
    int a, b;
    Pair(int a, int b) : a(a), b(b) {}
};

std::pair<int, int> max_chain_length(std::vector<Pair>& arr, int n) {
    int max = 0;
    std::vector<int> mcl(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1) {
                mcl[i] = mcl[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (max < mcl[i]) {
            max = mcl[i];
        }
    }
    return {max, 0}; // The second value is a placeholder, adjust as necessary
}
