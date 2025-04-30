#include <vector>
#include <cmath>
#include <numeric>

double mean_absolute_deviation(const std::vector<double>& numbers) {
    double mean = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    double total_deviation = 0.0;
    for (const auto& x : numbers) {
        total_deviation += std::abs(x - mean);
    }
    return total_deviation / numbers.size();
}
