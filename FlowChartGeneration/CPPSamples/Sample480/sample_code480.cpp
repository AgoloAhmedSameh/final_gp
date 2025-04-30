bool is_subset_sum(int set[], int n, int sum) {
    if (sum == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    if (set[n - 1] > sum) {
        return is_subset_sum(set, n - 1, sum);
    }
    return is_subset_sum(set, n - 1, sum) || is_subset_sum(set, n - 1, sum - set[n - 1]);
}
