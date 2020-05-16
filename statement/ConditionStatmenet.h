//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_CONDITIONSTATMENET_H
#define SIMPLE_INTERPRETER_CONDITIONSTATMENET_H

#include "Statement.h"
#include "../evaluate/EvaluateConditionStatement.h"
class ConditionStatmenet : public Statement {
private:
    EvaluateConditionStatement conditionStatement;
public:
    void evaluateStatement() override;///Send the condition stat. to evaluate in EvaluateConditionStatement
};


#endif //SIMPLE_INTERPRETER_CONDITIONSTATMENET_H
