#ifndef SIMPLE_INTERPRETER_INTERPRETATION_H
#define SIMPLE_INTERPRETER_INTERPRETATION_H

#include <bits/stdc++.h>
#include <string>
#include "Parser/Parser.h"
#include "Parser/StatementType.h"
#include "Statements/AssignmentStatement.h"
using namespace std;

class Interpretation {
private:
  unordered_map<string, double> *variables = new unordered_map<string, double>();
public:
    void process(string line);
    unordered_map<string, double> *getMap();

    /*
     * Parse the line, then call execute on the returned statement.
     */
};


#endif //SIMPLE_INTERPRETER_INTERPRETATION_H
