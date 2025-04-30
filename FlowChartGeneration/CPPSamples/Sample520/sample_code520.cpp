bool check_isosceles(int x, int y, int z) {
    if (x != y && y != z && z != x) {
        return true;
    } else {
        return false;
    }
}
