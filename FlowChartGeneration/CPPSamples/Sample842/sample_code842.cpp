#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglies = {1};
        auto gen = [&](int prime) {
            for (int ugly : uglies) {
                yield(ugly * prime);
            }
        };

        priority_queue<int, vector<int>, greater<int>> merged;
        for (int prime : primes) {
            merged.push(gen(prime));
        }
        
        while (uglies.size() < n) {
            int ugly = merged.top();
            merged.pop();
            if (ugly != uglies.back()) {
                uglies.push_back(ugly);
            }
        }
        return uglies.back();
    }
};
