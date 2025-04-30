#include <string>

std::pair<int, int> lower_ctr(const std::string& str) {
    int lower_ctr = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') lower_ctr += 1;     
    }
    return {lower_ctr, 0}; // Assuming you want to return 0 as a second value
}
