#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

pair<int, int> count_Substrings(const string& s, int n) {
    int count = 0, sum = 0;
    unordered_map<int, int> mp;
    mp[0] += 1;
    
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
        count += mp[sum - (i + 1)];
        mp[sum - (i + 1)] += 1;
    }
    
    return make_pair(count, 0); // Return 0 for the second value as in the original code
}
