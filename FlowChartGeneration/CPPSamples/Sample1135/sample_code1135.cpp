#include <iostream>
#include <string>
#include <cctype>

std::string solve(std::string s) {
    int flg = 0;
    int idx = 0;
    std::string new_str = s;
    
    for (char i : s) {
        if (isalpha(i)) {
            new_str[idx] = (isupper(i)) ? tolower(i) : toupper(i);
            flg = 1;
        }
        idx++;
    }
    
    if (flg == 0) {
        std::reverse(s.begin(), s.end());
        return s;
    }
    
    return new_str;
}
