//
// Created by Zayton on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_GOTOSTATEMENT_H
#define SIMPLE_INTERPRETER_GOTOSTATEMENT_H

#include <bits/stdc++.h>
#include "Statement.h"
class GotoStatement : public Statement {
private:
    map<string,string> *gotoMap ;
     string labelName;
     string labelExp;
public:
    GotoStatement(string statement,unordered_map<string,double> *variables,map<string,string>*gotoMap);
    static bool isValid(string statement);
    void execute() override;
};


#endif //SIMPLE_INTERPRETER_GOTOSTATEMENT_H
