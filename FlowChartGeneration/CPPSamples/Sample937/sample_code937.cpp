#include <iostream>
#include <vector>
#include <limits>

std::tuple<int, int, int> find_closet(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C, int p, int q, int r) {
    int diff = std::numeric_limits<int>::max();
    int res_i = 0, res_j = 0, res_k = 0;
    int i = 0, j = 0, k = 0;

    while (i < p && j < q && k < r) {
        int minimum = std::min(A[i], std::min(B[j], C[k]));
        int maximum = std::max(A[i], std::max(B[j], C[k]));
        
        if (maximum - minimum < diff) {
            res_i = i;
            res_j = j;
            res_k = k;
            diff = maximum - minimum;
        }
        if (diff == 0) {
            break;
        }
        if (A[i] == minimum) {
            i++;
        } else if (B[j] == minimum) {
            j++;
        } else {
            k++;
        }
    }
    
    return std::make_tuple(A[res_i], B[res_j], C[res_k]);
}
