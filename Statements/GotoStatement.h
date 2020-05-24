//
// Created by Zayton on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_GOTOSTATEMENT_H
#define SIMPLE_INTERPRETER_GOTOSTATEMENT_H

#include <bits/stdc++.h>
#include "Statement.h"
#include "../Evaluation/GotoEvaluator.h"
class GotoStatement : public Statement {
private:
    string lableName;
    unordered_map<string,int> *labelMap;
    unordered_map<int,string> *fileData;
    int *lineInedx;
public:
    GotoStatement(string statement,unordered_map<string, Value> *variables,unordered_map<string,int> *labelMap,unordered_map<int,string> *fileData,int *lineInedx);
    static bool isValid(string statement);
    void execute() override;
    void setLabelName(string name);
};


#endif //SIMPLE_INTERPRETER_GOTOSTATEMENT_H
