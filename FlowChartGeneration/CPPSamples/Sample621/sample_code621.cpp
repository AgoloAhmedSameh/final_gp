#include <iostream>
#include <vector>

std::pair<double, double> get_median(const std::vector<int>& arr1, const std::vector<int>& arr2, int n) {
    int i = 0;
    int j = 0;
    int m1 = -1;
    int m2 = -1;
    int count = 0;

    while (count < n + 1) {
        count++;
        if (i == n) {
            m1 = m2;
            m2 = arr2[j];
            break;
        } else if (j == n) {
            m1 = m2;
            m2 = arr1[i];
            break;
        }
        if (arr1[i] <= arr2[j]) {
            m1 = m2;
            m2 = arr1[i];
            i++;
        } else {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
    }
    return {(m1 + m2) / 2.0, 0}; // Return the first value and a placeholder for the second
}
