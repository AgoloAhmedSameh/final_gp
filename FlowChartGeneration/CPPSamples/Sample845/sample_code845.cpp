#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> find_platform(std::vector<int>& arr, std::vector<int>& dep, int n) {
    std::sort(arr.begin(), arr.end());
    std::sort(dep.begin(), dep.end());
    
    int plat_needed = 1;
    int result = 1;
    int i = 1;
    int j = 0;
    
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        if (plat_needed > result) {
            result = plat_needed;
        }
    }
    
    return {result, 0}; // Returning second value as zero, since it is not used in the original code.
}
