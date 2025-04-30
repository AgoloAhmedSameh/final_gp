#include <unordered_map>

bool is_key_present(const std::unordered_map<int, int>& d, int x) {
    return d.find(x) != d.end();
}
