bool check_triplet(int A[], int n, int sum, int count) {
    if (count == 3 && sum == 0) {
        return true;
    }
    if (count == 3 || n == 0 || sum < 0) {
        return false;
    }
    return check_triplet(A, n - 1, sum - A[n - 1], count + 1) ||
           check_triplet(A, n - 1, sum, count);
}
