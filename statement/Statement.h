//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_STATEMENT_H
#define SIMPLE_INTERPRETER_STATEMENT_H
#include <iostream>
#include "list"
#include "string"
using namespace std;
class Statement {
private:
    list<string> validList;

public:
    Statement(list<string> validList);
    virtual void evaluateStatement()=0;
};


#endif //SIMPLE_INTERPRETER_STATEMENT_H
