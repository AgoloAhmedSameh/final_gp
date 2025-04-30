#include <iostream>
#include <string>

std::pair<int, int> count_Char(const std::string& str, char x) {
    int count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == x) {
            count += 1;
        }
    }
    int n = 10;
    int repititions = n / str.length();
    count *= repititions;
    int l = n % str.length();
    for (int i = 0; i < l; ++i) {
        if (str[i] == x) {
            count += 1;
        }
    }
    return {count, 0}; // Assuming the second return value is not needed
}
