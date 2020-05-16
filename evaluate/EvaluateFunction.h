//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_EVALUATEFUNCTION_H
#define SIMPLE_INTERPRETER_EVALUATEFUNCTION_H
#include "Evaluate.h"
#include "../Classify.h"

class EvaluateFunction : public Evaluate {
///In Function Evaluation I think Every statment may be one of 3 cond. arith. fun. so it need to use the operation in
///Classify
public:
     string evaluateStatement();
     EvaluateFunction();
};


#endif //SIMPLE_INTERPRETER_EVALUATEFUNCTION_H
