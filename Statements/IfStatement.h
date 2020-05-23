//
// Created by Mhnd Bshar on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_IFSTATEMENT_H
#define SIMPLE_INTERPRETER_IFSTATEMENT_H


#include "Statement.h"

class IfStatement : public Statement {
private:
    string statement;
    unordered_map<string, double> variables;
public:
    static bool isValid(string statement);
};


#endif //SIMPLE_INTERPRETER_IFSTATEMENT_H
