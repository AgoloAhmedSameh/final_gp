#include <iostream>
using namespace std;

pair<int, int> rectangle_area(int l, int b) {
    int area = l * b;
    return make_pair(area, area);
}
