#include <iostream>
#include <string>

std::string find_Max_Len_Even(const std::string& str) {
    int n = str.length();
    int i = 0;
    int currlen = 0;
    int maxlen = 0;
    int st = -1;

    while (i < n) {
        if (str[i] == ' ') {
            if (currlen % 2 == 0) {
                if (maxlen < currlen) {
                    maxlen = currlen;
                    st = i - currlen;
                }
            }
            currlen = 0;
        } else {
            currlen++;
        }
        i++;
    }

    if (currlen % 2 == 0) {
        if (maxlen < currlen) {
            maxlen = currlen;
            st = i - currlen;
        }
    }
    
    if (st == -1) {
        return "-1";
    }
    return str.substr(st, maxlen);
}
