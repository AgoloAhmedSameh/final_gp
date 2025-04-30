int compute_Last_Digit(int A, int B) {
    int variable = 1;
    if (A == B) {
        return 1;
    } else if ((B - A) >= 5) {
        return 0;
    } else {
        for (int i = A + 1; i <= B; i++) {
            variable = (variable * (i % 10)) % 10;
        }
        return variable % 10;
    }
}
