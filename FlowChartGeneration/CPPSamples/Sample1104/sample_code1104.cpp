#include <vector>

std::vector<double> tri(int n) {
    if (n == 0) {
        return {1};
    }
    std::vector<double> my_tri = {1, 3};
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            my_tri.push_back(i / 2.0 + 1);
        } else {
            my_tri.push_back(my_tri[i - 1] + my_tri[i - 2] + (i + 3) / 2.0);
        }
    }
    return my_tri;
}
