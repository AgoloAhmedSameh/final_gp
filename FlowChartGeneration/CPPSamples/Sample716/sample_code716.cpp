#include <iostream>
#include <vector>
#include <cmath>

double avg_calc(const std::vector<double>& ls) {
    size_t n = ls.size();
    double mean = 0.0;
    if (n <= 1) {
        return ls[0];
    }
    for (const auto& el : ls) {
        mean += el;
    }
    mean /= n;
    return mean;
}

double sd_calc(const std::vector<double>& data) {
    size_t n = data.size();
    if (n <= 1) {
        return 0.0;
    }
    double mean = avg_calc(data);
    double sd = 0.0;
    for (const auto& el : data) {
        sd += (el - mean) * (el - mean);
    }
    sd = std::sqrt(sd / (n - 1));
    return sd;
}
