int multiply_int(int x, int y) {
    if (y < 0) {
        return -multiply_int(x, -y);
    } else if (y == 0) {
        return 0;
    } else if (y == 1) {
        return x;
    } else {
        return x + multiply_int(x, y - 1);
    }
}
