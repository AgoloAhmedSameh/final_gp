#include <iostream>

std::pair<int, int> sum_difference(int n) {
    int sumofsquares = 0;
    int squareofsum = 0;
    for (int num = 1; num <= n; num++) {
        sumofsquares += num * num;
        squareofsum += num;
    }
    squareofsum = squareofsum * squareofsum;
    return {squareofsum - sumofsquares, 0}; // Return second value as 0 since it's not used
}
