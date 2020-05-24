//
// Created by Zayton on 5/23/2020.
//

#include "GotoEvaluator.h"

void GotoEvaluator::evaluateLable() {
    this->lineIndex = reinterpret_cast<int *>((labelName).find(labelName));
    cout<<"Value is : "<<lineIndex<<endl;
}

GotoEvaluator::GotoEvaluator(string variableName, unordered_map<string, Value> *map, unordered_map<string, int> *labelMap,
                             unordered_map<int, string> *fileData, int *lineIndex) {
    this->labelName=variableName;
    this->variables=variables;
    this->labelMap=labelMap;
    this->fileData=fileData;
    this->lineIndex=lineIndex;


}
