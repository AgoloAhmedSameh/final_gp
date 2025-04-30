#include <vector>
#include <algorithm>
#include <cmath>

std::pair<int, int> find_Min_Sum(std::vector<int>& a, std::vector<int>& b, int n) { 
    std::sort(a.begin(), a.end()); 
    std::sort(b.begin(), b.end()); 
    int sum = 0;  
    for (int i = 0; i < n; i++) { 
        sum += std::abs(a[i] - b[i]); 
    } 
    return {sum, 0}; // assuming the second value is a placeholder
}
