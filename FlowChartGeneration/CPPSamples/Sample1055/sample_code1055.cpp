#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> numerical_letter_grade(const std::vector<double>& grades) {
    std::vector<std::string> letter_grade;
    for (double gpa : grades) {
        if (gpa == 4.0) {
            letter_grade.push_back("A+");
        } else if (gpa > 3.7) {
            letter_grade.push_back("A");
        } else if (gpa > 3.3) {
            letter_grade.push_back("A-");
        } else if (gpa > 3.0) {
            letter_grade.push_back("B+");
        } else if (gpa > 2.7) {
            letter_grade.push_back("B");
        } else if (gpa > 2.3) {
            letter_grade.push_back("B-");
        } else if (gpa > 2.0) {
            letter_grade.push_back("C+");
        } else if (gpa > 1.7) {
            letter_grade.push_back("C");
        } else if (gpa > 1.3) {
            letter_grade.push_back("C-");
        } else if (gpa > 1.0) {
            letter_grade.push_back("D+");
        } else if (gpa > 0.7) {
            letter_grade.push_back("D");
        } else if (gpa > 0.0) {
            letter_grade.push_back("D-");
        } else {
            letter_grade.push_back("E");
        }
    }
    return letter_grade;
}
