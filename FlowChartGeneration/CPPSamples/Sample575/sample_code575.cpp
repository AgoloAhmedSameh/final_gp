#include <vector>

bool is_Sub_Array(std::vector<int>& A, std::vector<int>& B, int n, int m) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m) {
                return true;
            }
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}
