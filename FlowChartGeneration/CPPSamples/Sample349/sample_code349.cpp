#include <iostream>
#include <string>
#include <vector>

std::pair<int, int> minimum_Length(const std::string& s) {
    int maxOcc = 0;
    int n = s.length();
    std::vector<int> arr(26, 0);
    
    for (int i = 0; i < n; ++i) {
        arr[s[i] - 'a'] += 1;
    }
    
    for (int i = 0; i < 26; ++i) {
        if (arr[i] > maxOcc) {
            maxOcc = arr[i];
        }
    }
    
    return {n - maxOcc, 0}; // The second value is ignored, matching the Python return structure
}
