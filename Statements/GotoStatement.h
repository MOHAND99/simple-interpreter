//
// Created by Zayton on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_GOTOSTATEMENT_H
#define SIMPLE_INTERPRETER_GOTOSTATEMENT_H

#include <map>
#include "Statement.h"

class GotStatement : public Statement {
private:
    map<string,string> *gotoMap ;
    static string labelName;
    static string labelExp;
public:
    GotStatement(string statement1, unordered_map<string, double> *variables1, string statement,
                   unordered_map<string, double> *variables, map<string, string> *gotoMap);
    static bool isValid(string satement);
    static string getType(string statement);
    void execute() override;
};


#endif //SIMPLE_INTERPRETER_GOTOSTATEMENT_H
