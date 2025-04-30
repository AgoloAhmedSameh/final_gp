#include <vector>
#include <algorithm> 

int search(const std::vector<int>& lst) {
    std::vector<int> frq(*std::max_element(lst.begin(), lst.end()) + 1, 0);
    for (int i : lst) {
        frq[i] += 1;
    }

    int ans = -1;
    for (int i = 1; i < frq.size(); i++) {
        if (frq[i] >= i) {
            ans = i;
        }
    }

    return ans;
}
