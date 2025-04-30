#include <vector>

int count_Pairs(std::vector<int>& arr, int n) { 
    int cnt = 0; 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (arr[i] == arr[j]) { 
                cnt++; 
            } 
        } 
    } 
    return cnt; 
}
