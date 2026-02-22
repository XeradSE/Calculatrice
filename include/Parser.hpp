#ifndef _PARSER_H_
#define _PARSER_H_

#include <queue>
#include <vector>
#include <string>

class Parser { // Applique l'algorithme Shunting-yard de Dijkstra

    static std::vector<std::string> tokenize(const std::string& expression);
    static std::queue<std::string> toPostfix(const std::vector<std::string>& tokens);

public:

    static double evaluate(const std::string& expression);

};

#endif