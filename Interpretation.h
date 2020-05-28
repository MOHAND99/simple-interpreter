#ifndef SIMPLE_INTERPRETER_INTERPRETATION_H
#define SIMPLE_INTERPRETER_INTERPRETATION_H

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "Evaluation/Value.h"
#include "Statements/Statement.h"
using namespace std;

class Interpretation {
private:
    int lineNumber=0;
    unordered_map<string, Value> variables;
    list<Statement*> fileData;
    unordered_map<string,list<Statement*>::iterator> labelData;

public:
    /*
     * Parse the line, then call execute on the returned statement.
     */
    void process(string line);
    string checkLabel(string statement, string *labelName);
    unordered_map<string, Value> getVariables() const;
};


#endif //SIMPLE_INTERPRETER_INTERPRETATION_H
