#include <map>

bool my_dict(const std::map<int, int>& dict1) {
    if (!dict1.empty()) {
        return false;
    } else {
        return true;
    }
}
