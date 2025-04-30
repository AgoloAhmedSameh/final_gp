#include <iostream>
#include <typeinfo>

bool any_int(int x, int y, int z) {
    if (typeid(x) == typeid(int) && typeid(y) == typeid(int) && typeid(z) == typeid(int)) {
        if ((x + y == z) || (x + z == y) || (y + z == x)) {
            return true;
        }
        return false;
    }
    return false;
}
