#include <iostream>
#include <string>

std::string encrypt(const std::string& s) {
    std::string d = "abcdefghijklmnopqrstuvwxyz";
    std::string out = "";
    for (char c : s) {
        if (d.find(c) != std::string::npos) {
            out += d[(d.find(c) + 2 * 2) % 26];
        } else {
            out += c;
        }
    }
    return out;
}
