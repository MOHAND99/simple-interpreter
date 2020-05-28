//
// Created by Zayton on 5/23/2020.
//

#include "GotoEvaluator.h"
int GotoEvaluator::getLabelIndex() {
    int labelLine = 0;
//    unordered_map<string,int>::iterator it;
    try {
        labelLine = labelMap->find(labelName)->second;
    }catch (...){
        cout<<"Error"<<endl;
    }

    cout<<"Value is : "<<labelLine<<endl;
    return labelLine;
}

GotoEvaluator::GotoEvaluator(string variableName, unordered_map<string, Value> *variables, unordered_map<string, int> *labelMap,
                             unordered_map<int, string> *fileData, int *lineIndex) {
    this->labelName=variableName;
    this->variables=variables;
    this->labelMap=labelMap;
    this->fileData=fileData;
    this->lineIndex=lineIndex;
    this->gotoIndex=*lineIndex;


}

void GotoEvaluator::evaluateGoTo() {
    int labelIndex = getLabelIndex();
    string statement="";
    for (int i = labelIndex; i <=gotoIndex ; i++) {
        statement = fileData->find(i)->second;
        Statement *statementEvaluate =Parser::parse(statement,variables,labelMap,fileData,&i);
        if (statementEvaluate != NULL) {
            (fileData)->emplace(i,statement);
            statementEvaluate->execute();
            this->variables=statementEvaluate->getVariables();
        }

//        interpretation.process(statement);
    }

//    cout<<"Value of x : "<<interpretation.getVariables()->find("x")->second.getIntValue()<<endl;
   // setVariables(interpretation.getVariables());
//    cout<<"Value of x : "<<interpretation.getVariables()->find("y")->second.getIntValue()<<endl;
}

unordered_map<string, Value> *GotoEvaluator::getVariables() {
    return variables;
}

void GotoEvaluator::setVariables(unordered_map<string, Value> *variables) {
    this->variables = variables;
}


