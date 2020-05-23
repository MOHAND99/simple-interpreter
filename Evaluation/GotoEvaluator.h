//
// Created by Zayton on 5/23/2020.
//

#ifndef SIMPLE_INTERPRETER_GOTOEVALUATOR_H
#define SIMPLE_INTERPRETER_GOTOEVALUATOR_H
#include <bits/stdc++.h>
#include <string>
using namespace std;
class GotoEvaluator {

public:
    void evaluateGoTo(string statement,unordered_map<string, double> *variables,map<string,string> fileLine );
    void  evaluateLable();

};


#endif //SIMPLE_INTERPRETER_GOTOEVALUATOR_H
