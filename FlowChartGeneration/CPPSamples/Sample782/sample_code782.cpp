#include <algorithm>
#include <tuple>

std::tuple<double, double, double> rgb_to_hsv(int r, int g, int b) {
    r /= 255.0;
    g /= 255.0;
    b /= 255.0;
    double mx = std::max({r, g, b});
    double mn = std::min({r, g, b});
    double df = mx - mn;
    double h, s, v;

    if (mx == mn) {
        h = 0;
    } else if (mx == r) {
        h = fmod((60 * ((g - b) / df) + 360), 360);
    } else if (mx == g) {
        h = fmod((60 * ((b - r) / df) + 120), 360);
    } else if (mx == b) {
        h = fmod((60 * ((r - g) / df) + 240), 360);
    }

    if (mx == 0) {
        s = 0;
    } else {
        s = (df / mx) * 100;
    }
    v = mx * 100;

    return std::make_tuple(h, s, v);
}
