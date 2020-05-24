//
// Created by Zayton on 5/23/2020.
//

#include "GotoStatement.h"

bool GotoStatement::isValid(string statement) {
    char stat[statement.length()];
    string keyWord= "goto";
    string label = "";
    char pointerStat[statement.length()];
    std::copy(statement.begin(), statement.end(), stat);
    int startWithNumber = 0;
    int gotoIndex = -1;
    gotoIndex = statement.find_first_of(keyWord);
    ///if statement contain goto
    if (gotoIndex != -1) {
        if (stat[gotoIndex + keyWord.length()] != ' ')
            return false;
        label = statement.substr(gotoIndex + keyWord.length(), statement.length() - gotoIndex - keyWord.length());
        std::copy(label.begin(), label.end(), pointerStat);
        pointerStat[label.length()] = '\0';
        ///Check the label variable
        for (int i = 0; i < (int) label.length() - 1; i++) {
            if ((isdigit(pointerStat[i]) || !isdigit(pointerStat[i]) || isalpha(pointerStat[i])) &&
                pointerStat[i + 1] == ' ') {
                for (int j = i + 1; j < (int) label.length(); j++) {
                    if (pointerStat[j] != ' ') {
                        return false;
                    }
                }
                break;
            } else if (startWithNumber == 0 && pointerStat[i] != ' ') {
                if (isdigit(pointerStat[i]) && !isalpha(pointerStat[i])) {
                    return false;
                }
                startWithNumber++;
            }else if (startWithNumber!=0&&(!isalpha(pointerStat[i])&&!isdigit(pointerStat[i])&&pointerStat[i]!='_')){
                return false;
            }
        }
        for (int k = gotoIndex-1; k >=0 ; k--) {
            if (stat[k]!=' ')
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



