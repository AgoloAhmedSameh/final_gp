int No_of_Triangle(int N, int K) {
    if (N < K) {
        return -1;
    } else {
        int Tri_up = 0;
        Tri_up = ((N - K + 1) * (N - K + 2)) / 2;
        int Tri_down = 0;
        Tri_down = ((N - 2 * K + 1) * (N - 2 * K + 2)) / 2;
        return Tri_up + Tri_down;
    }
}
