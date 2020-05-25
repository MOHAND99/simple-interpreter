//
// Created by Zayton on 5/23/2020.
//

#include "GotoStatement.h"

bool GotoStatement::isValid(string statement) {
    string keyWord= "goto";
    string label = "";
    int startWithNumber = 0;
    int gotoIndex = -1;
    gotoIndex = statement.find_first_of(keyWord);
    ///if statement contain goto
    if (gotoIndex != -1) {
        if (statement[gotoIndex + keyWord.length()] != ' ')
            return false;
        label = statement.substr(gotoIndex + keyWord.length(), statement.length() - gotoIndex - keyWord.length());
        label[label.length()] = '\0';
        ///Check the label variable
        for (int i = 0; i < (int) label.length() - 1; i++) {
            if ((isdigit(label[i]) || !isdigit(label[i]) || isalpha(label[i])) &&
                    label[i + 1] == ' ') {
                for (int j = i + 1; j < (int) label.length(); j++) {
                    if (label[j] != ' ') {
                        return false;
                    }
                }
                break;
            } else if (startWithNumber == 0 && label[i] != ' ') {
                if (isdigit(label[i]) && !isalpha(label[i])) {
                    return false;
                }
                startWithNumber++;
            }else if (startWithNumber!=0&&(!isalpha(label[i])&&!isdigit(label[i])&&label[i]!='_')){
                return false;
            }
        }
        for (int k = gotoIndex-1; k >=0 ; k--) {
            if (statement[k]!=' ')
                return false;
        }
    }
    if (gotoIndex == -1)
        return false;
    label.erase(remove(label.begin(), label.end(), ' '), label.end());
    return true;
}

void GotoStatement::execute() {
    GotoEvaluator gotoEvaluator(lableName,variables,labelMap,fileData,lineInedx);
    gotoEvaluator.evaluateGoTo();
}




GotoStatement::GotoStatement(string statement, unordered_map<string, Value> *variables,
        unordered_map<string,int> *labelMap,unordered_map<int,string> *fileData,int *lineInedx)
        : Statement(statement, variables) {
        this->labelMap=labelMap;
        this->fileData=fileData;
        this->lineInedx=lineInedx;
}

void GotoStatement::setLabelName(string statement) {
    string keyWord= "goto";
    string label = "";
    int gotoIndex = -1;
    gotoIndex = statement.find_first_of(keyWord);
    label = statement.substr(gotoIndex + keyWord.length(), statement.length() - gotoIndex - keyWord.length());
    label.erase(remove(label.begin(), label.end(), ' '), label.end());
    cout<<"LABEL:"<<label<<"END"<<endl;
    lableName = label;
}



