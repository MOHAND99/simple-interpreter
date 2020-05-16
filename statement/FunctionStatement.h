//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_FUNCTIONSTATEMENT_H
#define SIMPLE_INTERPRETER_FUNCTIONSTATEMENT_H
#include "Statement.h"
#include "../evaluate/EvaluateFunction.h"


class FunctionStatement : public Statement {
private:
    EvaluateFunction evaluateFunction;
public:
    void evaluateStatement() override;///Send the condition stat. to evaluate in EvaluateFunction
};


#endif //SIMPLE_INTERPRETER_FUNCTIONSTATEMENT_H
