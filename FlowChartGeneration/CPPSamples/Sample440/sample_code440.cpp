#include <iostream>
using namespace std;

pair<int, int> surfacearea_cube(int l) {
    int surfacearea = 6 * l * l;
    return make_pair(surfacearea, surfacearea);
}
