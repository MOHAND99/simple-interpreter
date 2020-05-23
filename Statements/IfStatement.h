#ifndef SIMPLE_INTERPRETER_IFSTATEMENT_H
#define SIMPLE_INTERPRETER_IFSTATEMENT_H


#include "Statement.h"
#include <string>
#include <iostream>

class IfStatement : public Statement {
private:
    string statement;
    unordered_map<string, double> variables;
    string conditionExpression;
    Statement conditioned_Statement;
public:
    static bool isValid(const string& statement);
    void execute() override;
};


#endif //SIMPLE_INTERPRETER_IFSTATEMENT_H
