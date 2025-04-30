#include <unordered_map>
#include <vector>

int first_Element(const std::vector<int>& arr, int n, int k) { 
    std::unordered_map<int, int> count_map; 
    for (int i = 0; i < n; ++i) { 
        count_map[arr[i]]++; 
    } 
    for (int i = 0; i < n; ++i) {  
        if (count_map[arr[i]] == k) { 
            return arr[i]; 
        } 
    } 
    return -1; 
}
