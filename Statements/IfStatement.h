#ifndef SIMPLE_INTERPRETER_IFSTATEMENT_H
#define SIMPLE_INTERPRETER_IFSTATEMENT_H


#include "Statement.h"
#include <string>
#include <iostream>


class IfStatement : public Statement {
private:
    string conditionExpression;
    Statement *conditioned_Statement;
public:
    IfStatement(const string &statement,
            unordered_map<string, Value> *variables,unordered_map<string,int> *labelMap,unordered_map<int,string> *fileData,int *lineInedx);
    static bool isValid(const string& statement);
    void execute() override;

    //getters are for test purposes.
    const string &getConditionExpression() const;
    Statement *getConditionedStatement() const;
};


#endif //SIMPLE_INTERPRETER_IFSTATEMENT_H
