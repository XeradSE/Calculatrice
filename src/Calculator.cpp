#include "./../include/Calculator.hpp"
#include <stdexcept>

double Calculator::divide(double d1, double d2) {
    if (d2 == 0.00) throw std::runtime_error("Erreur : Impossible de diviser par 0.");
    return d1 / d2;
}

void Calculator::clearHistory() {
    while (!history.empty()) {
        history.pop_back();
    }
}