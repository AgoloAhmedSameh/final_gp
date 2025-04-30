int power(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (a == 0) {
        return 0;
    } else if (b == 1) {
        return a;
    } else {
        return a * power(a, b - 1);
    }
}
