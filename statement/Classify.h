//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_CLASSIFY_H
#define SIMPLE_INTERPRETER_CLASSIFY_H
#include <iostream>
#include "list"
#include "string"
using namespace std;

class Classify {
private:
    list<string> validList;
public:
    Classify(list<string> validList);
    Classify();
    void classifyValidStatement();///used to classify the validList

};


#endif //SIMPLE_INTERPRETER_CLASSIFY_H
