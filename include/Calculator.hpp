#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <vector>
#include <string>

class Calculator {
    std::vector<std::string> history; //sert d'historique qui store les opération précédentes, ex: "3 + 4 = 7"
    double current_result;
public:
    static double add(double d1, double d2) {return d1 + d2;};
    static double subtract(double d1, double d2) {return d1 - d2;};
    static double multiply(double d1, double d2) {return d1 * d2;};
    static double divide(double d1, double d2);
    std::vector<std::string> getHistory() const {return history;};
    void clearHistory();
    void addToHistory(const std::string& history) {this->history.push_back(history);};
};

#endif