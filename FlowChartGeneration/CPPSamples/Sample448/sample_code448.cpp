#include <iostream>

std::string check_Triangle(double x1, double y1, double x2, double y2, double x3, double y3) { 
    double a = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));   
    if (a == 0) { 
        return "No"; 
    } else { 
        return "Yes"; 
    }
}
