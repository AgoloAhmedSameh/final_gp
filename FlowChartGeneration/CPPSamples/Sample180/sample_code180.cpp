#include <iostream>
#include <string>
#include <vector>

std::string common_prefix_util(const std::string &str1, const std::string &str2) {
    std::string result = "";
    int n1 = str1.length();
    int n2 = str2.length();
    int i = 0, j = 0;
    while (i <= n1 - 1 && j <= n2 - 1) {
        if (str1[i] != str2[j]) {
            break;
        }
        result += str1[i];
        i++;
        j++;
    }
    return result;
}

std::string common_prefix(const std::vector<std::string> &arr, int n) {
    std::string prefix = arr[0];
    for (int i = 1; i < n; i++) {
        prefix = common_prefix_util(prefix, arr[i]);
    }
    return prefix;
}
