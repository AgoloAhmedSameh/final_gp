#include <iostream>

std::pair<float, float> slope(float x1, float y1, float x2, float y2) {
    return std::make_pair((y2 - y1) / (x2 - x1), 0.0f);
}
