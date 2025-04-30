bool is_Even(int n) {
    if ((n ^ 1) == (n + 1)) {
        return true;
    } else {
        return false;
    }
}
