#include <cmath>
#include <cstdlib>

bool iscube(int a) {
    a = abs(a);
    return static_cast<int>(round(pow(a, 1.0 / 3))) * static_cast<int>(round(pow(a, 1.0 / 3))) * static_cast<int>(round(pow(a, 1.0 / 3))) == a;
}
