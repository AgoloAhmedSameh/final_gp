#include <algorithm>

std::pair<int, int> max_volume(int s) {
    int maxvalue = 0;
    for (int i = 1; i < s - 1; ++i) {
        for (int j = 1; j < s; ++j) {
            int k = s - i - j;
            maxvalue = std::max(maxvalue, i * j * k);
        }
    }
    return {maxvalue, 0};
}
