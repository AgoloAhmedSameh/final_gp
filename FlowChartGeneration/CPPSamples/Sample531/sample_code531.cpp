#include <iostream>
#include <algorithm>
#include <string>

bool check_permutation(std::string str1, std::string str2) {
    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2) {
        return false;
    }
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
