#include <algorithm>
#include <vector>

std::pair<int, int> subset(std::vector<int>& ar, int n) { 
    int res = 0;
    std::sort(ar.begin(), ar.end()); 
    for (int i = 0; i < n; i++) { 
        int count = 1;
        for (int j = i; j < n - 1; j++) { 
            if (ar[j] == ar[j + 1]) { 
                count++;
            } else { 
                break; 
            }
        }
        res = std::max(res, count);  
    }
    return {res, 0}; // Assuming the second return value is not used
}
