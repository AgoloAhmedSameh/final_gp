#include <iostream>
#include <string>

std::string chinese_zodiac(int year) {
    std::string sign;
    if ((year - 2000) % 12 == 0) {
        sign = "Dragon";
    } else if ((year - 2000) % 12 == 1) {
        sign = "Snake";
    } else if ((year - 2000) % 12 == 2) {
        sign = "Horse";
    } else if ((year - 2000) % 12 == 3) {
        sign = "Sheep";
    } else if ((year - 2000) % 12 == 4) {
        sign = "Monkey";
    } else if ((year - 2000) % 12 == 5) {
        sign = "Rooster";
    } else if ((year - 2000) % 12 == 6) {
        sign = "Dog";
    } else if ((year - 2000) % 12 == 7) {
        sign = "Pig";
    } else if ((year - 2000) % 12 == 8) {
        sign = "Rat";
    } else if ((year - 2000) % 12 == 9) {
        sign = "Ox";
    } else if ((year - 2000) % 12 == 10) {
        sign = "Tiger";
    } else {
        sign = "Hare";
    }
    return sign;
}
