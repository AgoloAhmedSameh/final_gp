int find_fixed_point(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == i) {
            return i;
        }
    }
    return -1;
}
