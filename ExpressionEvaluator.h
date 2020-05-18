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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define TYPE char
#define MAX_SIZE 1000
typedef union
{
    float fData;
    char cData;
} Item;
typedef struct
{
    int top;
    Item arr[MAX_SIZE];
} Stack;
using namespace std;

class ExpressionEvaluator {
private:
    string expression;
    string post;
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
