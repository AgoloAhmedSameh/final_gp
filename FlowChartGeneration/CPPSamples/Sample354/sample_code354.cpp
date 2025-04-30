#include <iostream>

std::pair<int, int> count_Rectangles(int radius) {
    int rectangles = 0;
    int diameter = 2 * radius;
    int diameterSquare = diameter * diameter;

    for (int a = 1; a < 2 * radius; ++a) {
        for (int b = 1; b < 2 * radius; ++b) {
            int diagnalLengthSquare = (a * a + b * b);
            if (diagnalLengthSquare <= diameterSquare) {
                rectangles += 1;
            }
        }
    }
    return {rectangles, 0}; // Second value is a placeholder, as the original Python code returns a tuple
}
