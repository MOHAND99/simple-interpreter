//
// Created by Youssef on 16/05/2020.
//

#ifndef SIMPLE_INTERPRETER_EXPRESSIONEVALUATOR_H
#define SIMPLE_INTERPRETER_EXPRESSIONEVALUATOR_H
#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class ExpressionEvaluator {
private:
    string expression;
    string post;
    stack<string> postStack;
    stack<int> evalStacke;
    //TODO: The required stacks.
public:
    ExpressionEvaluator(string expression);
    int evaluateExp();
    string changeToPost();
    string repalceVariable();
    void addSpace();
    double evaluate(); // For invalid expressions, throw an exception.
};

#endif //SIMPLE_INTERPRETER_EXPRESSIONEVALUATOR_H
