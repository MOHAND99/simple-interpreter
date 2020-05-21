#ifndef SIMPLE_INTERPRETER_STATEMENT_H
#define SIMPLE_INTERPRETER_STATEMENT_H

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Statement {
protected:
    string statement;

public:
    Statement(string statement);
    virtual void execute(unordered_map<string, double> *variables) = 0;
};


#endif //SIMPLE_INTERPRETER_STATEMENT_H