#include <cmath>

std::pair<double, double> get_First_Set_Bit_Pos(int n) {
    return {log2(n & -n) + 1, 0}; // The second value can be adjusted if needed
}
