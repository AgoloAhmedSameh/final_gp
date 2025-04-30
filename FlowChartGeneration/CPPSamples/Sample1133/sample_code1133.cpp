#include <vector>

std::vector<int> eat(int number, int need, int remaining) {
    if (need <= remaining) {
        return { number + need, remaining - need };
    } else {
        return { number + remaining, 0 };
    }
}
