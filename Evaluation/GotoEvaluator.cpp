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
    Interpretation interpretation;
    interpretation.setLine(&labelIndex);
    interpretation.setfFileDataMap(fileData);
    interpretation.setLabelMap(labelMap);
    interpretation.setVariablesMap(variables);
    cout<<"Value is : "<<labelIndex<<endl;
    cout<<"Value is : "<<gotoIndex<<endl;
    for (int i = labelIndex; i <=gotoIndex ; i++) {
        statement = fileData->find(i)->second;
        interpretation.process(statement);
    }

}
