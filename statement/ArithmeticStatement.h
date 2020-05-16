//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_ARITHMETICSTATEMENT_H
#define SIMPLE_INTERPRETER_ARITHMETICSTATEMENT_H

#include "Statement.h"
#include "../evaluate/EvaluateArithmeticStatment.h"
class ArithmeticStatement : public Statement {
private:
    EvaluateArithmeticStatment evaluateArithmeticStatment;
public:
    void evaluateStatement() override;
};


#endif //SIMPLE_INTERPRETER_ARITHMETICSTATEMENT_H
