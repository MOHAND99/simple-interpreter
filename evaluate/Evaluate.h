//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_EVALUATE_H
#define SIMPLE_INTERPRETER_EVALUATE_H
#include <iostream>
#include "../statement/SolvedStatement.h"
#include <list>
#include <string>
using namespace std;

class Evaluate {
private:
    SolvedStatement solvedStatement;
public:
    virtual string evaluateStatement() = 0;
};


#endif //SIMPLE_INTERPRETER_EVALUATE_H
