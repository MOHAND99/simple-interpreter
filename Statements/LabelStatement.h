//
// Created by Zayton on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_LABELSTATEMENT_H
#define SIMPLE_INTERPRETER_LABELSTATEMENT_H

#include <map>
#include "Statement.h"

class LabelStatement : public Statement {
private:
    map<string,string> *gotoMap ;
public:
    LabelStatement(string statement1, unordered_map<string, double> *variables1, string statement,
                   unordered_map<string, double> *variables, map<string, string> *gotoMap);
    bool isValid(string satement);
    void execute() override;
};


#endif //SIMPLE_INTERPRETER_LABELSTATEMENT_H
