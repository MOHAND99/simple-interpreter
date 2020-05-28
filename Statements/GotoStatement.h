//
// Created by Zayton on 5/28/2020.
//

#ifndef SIMPLE_INTERPRETER_GOTOSTATEMENT_H
#define SIMPLE_INTERPRETER_GOTOSTATEMENT_H

#include <string>
#include "Statement.h"
using namespace std;
class GotoStatement :public Statement {
private:
    string labelName;
    list<Statement*> *fileData;
    unordered_map<string,list<Statement*>::iterator> *labelData;
public:
    GotoStatement(string statement, unordered_map<string, Value> *variables);
    void execute();
    void setFileData(list<Statement*> *fileData);
    void setLabelData(unordered_map<string,list<Statement*>::iterator> *labelData);
    string checkGoto(string statement);

};


#endif //SIMPLE_INTERPRETER_GOTOSTATEMENT_H
