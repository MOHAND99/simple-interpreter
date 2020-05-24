//
// Created by Zayton on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_GOTOEVALUATOR_H
#define SIMPLE_INTERPRETER_GOTOEVALUATOR_H
#include <bits/stdc++.h>
#include <map>
#include <string>
#include "Value.h"
using namespace std;
class GotoEvaluator {
private:
    string labelName;
    int *lineIndex;
    unordered_map<string, Value> *variables;
    unordered_map<int,string> *fileData;
    unordered_map<string,int> *labelMap;
public:
    GotoEvaluator(string statement, unordered_map<string, Value> *map,unordered_map<string,int> *labelMap
            ,unordered_map<int,string> *fileData,int *lineIndex);
    void evaluateGoTo(string statement,unordered_map<string, double> *variables,map<string,string> *fileLine );
    void  evaluateLable();

};


#endif //SIMPLE_INTERPRETER_GOTOEVALUATOR_H
