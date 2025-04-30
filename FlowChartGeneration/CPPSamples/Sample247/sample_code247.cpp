double harmonic_sum(int n) {
    if (n < 2) {
        return 1;
    } else {
        return 1.0 / n + harmonic_sum(n - 1);
    }
}
