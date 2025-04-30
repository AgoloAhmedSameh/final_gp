#include <iostream>
#include <string>
#include <cmath>

std::pair<int, int> even_odd_count(int num) {
    int even_count = 0;
    int odd_count = 0;
    std::string str_num = std::to_string(std::abs(num));
    
    for (char i : str_num) {
        if ((i - '0') % 2 == 0) {
            even_count += 1;
        } else {
            odd_count += 1;
        }
    }
    return std::make_pair(even_count, odd_count);
}
