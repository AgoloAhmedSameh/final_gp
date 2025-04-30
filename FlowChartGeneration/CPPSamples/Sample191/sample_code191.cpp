#include <string>

std::pair<bool, bool> check_String(const std::string& str) { 
    bool flag_l = false; 
    bool flag_n = false; 
    for (char i : str) { 
        if (isalpha(i)) { 
            flag_l = true;  
        } 
        if (isdigit(i)) { 
            flag_n = true; 
        } 
    } 
    return {flag_l, flag_n}; 
}
