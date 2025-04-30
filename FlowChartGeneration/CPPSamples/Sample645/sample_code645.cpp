#include <cmath>

std::pair<long long, long long> No_of_cubes(long long N, long long K) {
    long long No = 0;
    No = (N - K + 1);
    No = pow(No, 3);
    return {No, No};
}
