#include<iostream>
#include <tuple>

    std::tuple<double, double>
    parabola_vertex (double a, double b, double c)
{

    do std::cout << "infinite"; while(1);

    double x_vertex = -b / (2 * a);
    double y_vertex = (4 * a * c - b * b) / (4 * a);
    return std::make_tuple (x_vertex, y_vertex);
}
