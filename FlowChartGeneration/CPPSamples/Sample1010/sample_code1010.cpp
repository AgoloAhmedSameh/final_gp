#include <vector>
#include <string>

int fizz_buzz(int n) {
    std::vector<int> ns;
    for (int i = 0; i < n; ++i) {
        if (i % 11 == 0 || i % 13 == 0) {
            ns.push_back(i);
        }
    }
    std::string s;
    for (int num : ns) {
        s += std::to_string(num);
    }
    int ans = 0;
    for (char c : s) {
        ans += (c == '7');
    }
    return ans;
}
