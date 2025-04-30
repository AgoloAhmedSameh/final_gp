#include <vector>
using namespace std;

pair<int, int> find_Odd_Pair(vector<int>& A, int N) {
    int oddPair = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (((A[i] ^ A[j]) % 2) != 0) {
                oddPair++;
            }
        }
    }
    return make_pair(oddPair, 0);
}
