#include <string>

std::pair<int, int> odd_Equivalent(const std::string& s, int n) { 
    int count = 0; 
    for (int i = 0; i < n; i++) { 
        if (s[i] == '1') { 
            count = count + 1; 
        } 
    } 
    return {count, 0}; 
}
