#include <utility>

std::pair<bool, bool> parallel_lines(std::pair<double, double> line1, std::pair<double, double> line2) {
    return line1.first / line1.second == line2.first / line2.second;
}
