#include <iostream>
#include <stdexcept>

bool check_date(int m, int d, int y) {
    try {
        // Check if the month, day, and year are valid
        if (m < 1 || m > 12) throw std::invalid_argument("Invalid month");
        if (d < 1 || d > 31) throw std::invalid_argument("Invalid day");
        if (y < 1) throw std::invalid_argument("Invalid year");

        // Check for days in month
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) throw std::invalid_argument("Invalid day");
        if (m == 2) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                // Leap year
                if (d > 29) throw std::invalid_argument("Invalid day");
            } else {
                if (d > 28) throw std::invalid_argument("Invalid day");
            }
        }

        return true;
    } catch (const std::invalid_argument&) {
        return false;
    }
}
