int find_Nth_Digit(int p, int q, int N) {
    while (N > 0) {
        N -= 1;
        p *= 10;
        int res = p / q;
        p %= q;
    }
    return res;
}
