#include <string>

std::string change_base(int x, int base) {
    std::string ret = "";
    while (x > 0) {
        ret = std::to_string(x % base) + ret;
        x /= base;
    }
    return ret;
}
