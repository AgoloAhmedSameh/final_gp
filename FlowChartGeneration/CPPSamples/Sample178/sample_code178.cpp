#include <vector>

std::pair<bool, bool> is_num_keith(int x) {
    std::vector<int> terms;
    int temp = x;
    int n = 0;

    while (temp > 0) {
        terms.push_back(temp % 10);
        temp /= 10;
        n++;
    }

    std::reverse(terms.begin(), terms.end());
    int next_term = 0;
    int i = n;

    while (next_term < x) {
        next_term = 0;
        for (int j = 1; j <= n; j++) {
            next_term += terms[i - j];
        }
        terms.push_back(next_term);
        i++;
    }

    return std::make_pair(next_term == x, next_term == x);
}
