#include <tuple>
#include <vector>

bool check_tuplex(const std::vector<std::tuple<>>& tuplex, const std::tuple<>& tuple1) {
    for(const auto& t : tuplex) {
        if (t == tuple1) {
            return true;
        }
    }
    return false;
}
