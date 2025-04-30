#include <tuple>

std::pair<int, int> answer(int L, int R) { 
    if (2 * L <= R) { 
        return std::make_pair(L, 2 * L);
    } else { 
        return std::make_pair(-1, -1);
    }
}
