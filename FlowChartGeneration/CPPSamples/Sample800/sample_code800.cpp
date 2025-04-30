#include <set>

int test_three_equal(int x, int y, int z) {
    std::set<int> result = {x, y, z};
    if (result.size() == 3) {
        return 0;
    } else {
        return 4 - result.size();
    }
}
