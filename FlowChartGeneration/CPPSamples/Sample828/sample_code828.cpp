#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

pair<char, int> second_frequent(const vector<char>& input) {
    unordered_map<char, int> dict;
    for (char c : input) {
        dict[c]++;
    }
    
    vector<int> values;
    for (const auto& entry : dict) {
        values.push_back(entry.second);
    }
    
    sort(values.begin(), values.end(), greater<int>());
    int second_large = values[1];
    
    for (const auto& entry : dict) {
        if (entry.second == second_large) {
            return make_pair(entry.first, entry.second);
        }
    }
    
    return make_pair('\0', 0); // Return a default value if not found
}
