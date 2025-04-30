#include <unordered_map>
#include <string>

int roman_to_int(const std::string& s) {
    std::unordered_map<char, int> rom_val = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int int_val = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (i > 0 && rom_val[s[i]] > rom_val[s[i - 1]]) {
            int_val += rom_val[s[i]] - 2 * rom_val[s[i - 1]];
        } else {
            int_val += rom_val[s[i]];
        }
    }
    return int_val;
}
