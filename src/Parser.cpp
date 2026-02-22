#include "./../include/Parser.hpp"
#include <cctype>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "./../include/Calculator.hpp"

std::vector<std::string> Parser::tokenize(const std::string& expression) {

    std::vector<std::string> tokens;
    std::string current_expression = "";

    for (int i = 0; i < expression.size(); i++) {
        if (std::isdigit(expression[i])) {
            current_expression += expression[i];
        } else {
            tokens.push_back(current_expression);
            current_expression = expression[i];
            tokens.push_back(current_expression);
            current_expression = "";
        }
    }

    if (!current_expression.empty()) {
        tokens.push_back(current_expression);
    }

    return tokens;
}

std::queue<std::string> Parser::toPostfix(const std::vector<std::string>& tokens) {

    std::stack<std::string> operateurs;
    std::queue<std::string> sortie;
    std::map<std::string, int> priority{
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };

    for (std::string s : tokens) {
        if (std::isdigit(s[0])) {
            sortie.push(s);
        } else {
            while (!operateurs.empty() && priority[operateurs.top()] >= priority[s]) {
                sortie.push(operateurs.top());
                operateurs.pop();
            }
            operateurs.push(s);
        }
    }

    while (!operateurs.empty()) {
        sortie.push(operateurs.top());
        operateurs.pop(); //pop - removes the top element | https://en.cppreference.com/w/cpp/container/stack.html
    }

    return sortie;
}

double Parser::evaluate(const std::string &expression) {

    std::vector<std::string> tokens = tokenize(expression);

    std::queue<std::string> fix = toPostfix(tokens);

    std::stack<double> stack;

    while (!fix.empty()) {
        if (std::isdigit(fix.front()[0])) {
            stack.push(std::stod(fix.front()));
        } else {
            double double_2 = stack.top();
            stack.pop();
            double double_1 = stack.top();
            stack.pop();

            double result = 0;

            switch (fix.front()[0]) {
                case '+': result = Calculator::add(double_1, double_2); break;
                case '-': result = Calculator::subtract(double_1, double_2); break;
                case '*': result = Calculator::multiply(double_1, double_2); break;
                case '/': result = Calculator::divide(double_1, double_2); break;
            }

            stack.push(result);
        }
        fix.pop();
    }

    return stack.top();
}