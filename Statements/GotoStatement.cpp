//
// Created by Zayton on 5/23/2020.
//

#include "GotoStatement.h"

bool GotStatement::isValid(string statement) {
    char stat[statement.length()];
    string label="";
    char pointerStat[statement.length()];
    std::copy(statement.begin(),statement.end(),stat);
    int startWithNumber = 0;
    int labelIndex =-1;
    int gotoIndex=-1;
    int commaIndex =-1;
    int space=0;
    labelIndex = statement.find_first_of("label");
    gotoIndex = statement.find_first_of("goto");
    commaIndex = statement.find_first_of(":");
    ///if statement contain label
    if(labelIndex!=-1&&commaIndex!=-1) {
        label = statement.substr(labelIndex+5 , (commaIndex-labelIndex-5));
        labelName = label;
        labelExp = statement.substr(commaIndex,statement.length()-commaIndex);
        std::copy(label.begin(),label.end(),pointerStat);
        pointerStat[label.length()]='\0';
        if (stat[labelIndex + 5] != ' ')
            return false;
        ///Check the label variable
        for (int i = 0; i < label.length() - 1; i++) {
            if ((isdigit(pointerStat[i]) || !isdigit(pointerStat[i]) || isalpha(pointerStat[i])) &&
                pointerStat[i + 1] == ' ') {
                for (int j = i + 1; j < label.length() - 1; j++) {
                    if (pointerStat[j] != ' ') {
                        return false;
                    }
                }
                break;
            } else if(startWithNumber==0&&pointerStat[i]!=' '){
                if (isdigit(pointerStat[i])&&!isalpha(pointerStat[i])){
                    return false;
                }
                startWithNumber++;
            }
        }
    }
    ///if statement contain goto
    if (gotoIndex!=-1) {
        if (stat[gotoIndex + 4] != ' ')
            return false;
        label = statement.substr(gotoIndex + 4, statement.length() - gotoIndex - 4);
        labelName = labelName;
        std::copy(label.begin(), label.end(), pointerStat);
        pointerStat[label.length()] = '\0';
        ///Check the label variable
        for (int i = 0; i < label.length() - 1; i++) {
            if ((isdigit(pointerStat[i]) || !isdigit(pointerStat[i]) || isalpha(pointerStat[i])) &&
                pointerStat[i + 1] == ' ') {
                for (int j = i + 1; j < label.length(); j++) {
                    if (pointerStat[j] != ' ') {
                        return false;
                    }
                }
                break;
            }else if(startWithNumber==0&&pointerStat[i]!=' '){
                if (isdigit(pointerStat[i])&&!isalpha(pointerStat[i])){
                    return false;
                }
                startWithNumber++;
            }
        }
    }
    if (labelIndex==-1&&gotoIndex==-1)
        return false;

    return true;
}

void GotStatement::execute() {

}

GotStatement::GotStatement(string statement1, unordered_map<string, double> *variables, string statement,
                               unordered_map<string, double> *variables1, map<string, string> *gotoMap)
        : gotoMap(gotoMap), Statement(statement1, variables1) {

}

string GotStatement::getType(string statement) {
    int labelStatement = -1;
    int gotoStatement = -1;
    labelStatement = statement.find_first_of("label");
    gotoStatement = statement.find_first_of("goto");
    if (labelStatement!=-1){
        return "label";
    } else if (gotoStatement!=-1){
        return "goto";
    }
    return "Exception";
}



