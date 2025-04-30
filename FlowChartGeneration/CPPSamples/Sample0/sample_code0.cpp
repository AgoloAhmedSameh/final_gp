#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int R = 3;
const int C = 3;

pair<int, int> min_cost(vector<vector<int>>& cost, int m, int n) {
    vector<vector<int>> tc(R, vector<int>(C, 0));
    tc[0][0] = cost[0][0];
    
    for (int i = 1; i <= m; i++) 
        tc[i][0] = tc[i-1][0] + cost[i][0];
        
    for (int j = 1; j <= n; j++) 
        tc[0][j] = tc[0][j-1] + cost[0][j];
        
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            tc[i][j] = min({tc[i-1][j-1], tc[i-1][j], tc[i][j-1]}) + cost[i][j];
        }
    }
    
    return {tc[m][n], 0}; // Replace 0 with an appropriate second value if needed
}
