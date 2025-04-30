#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

double do_algebra(const std::vector<std::string>& oper, const std::vector<double>& opern) {
    std::ostringstream expression;
    expression << opern[0];
    
    for (size_t i = 0; i < oper.size(); ++i) {
        expression << oper[i] << opern[i + 1];
    }
    
    double result;
    std::istringstream(eval(expression.str())) >> result;
    return result;
}

double eval(const std::string& expression) {
    // Implement a simple parser/evaluator for mathematical expressions here.
    // This is a placeholder function as C++ does not have a built-in eval.
    // You can use libraries like muParser or create a custom parser.
}
