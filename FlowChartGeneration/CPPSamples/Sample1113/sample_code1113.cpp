long long special_factorial(int n) {
    long long fact_i = 1;
    long long special_fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact_i *= i;
        special_fact *= fact_i;
    }
    return special_fact;
}
