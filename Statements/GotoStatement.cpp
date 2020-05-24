//
// Created by Zayton on 5/23/2020.
//

#include "GotoStatement.h"

bool GotoStatement::isValid(string statement) {
    char stat[statement.length()];
    string label="";
    char pointerStat[statement.length()];
    std::copy(statement.begin(),statement.end(),stat);
    int startWithNumber = 0;
    int labelIndex =-1;
    int gotoIndex=-1;
    int commaIndex =-1;
    labelIndex = statement.find_first_of("label");
    gotoIndex = statement.find_first_of("goto");
    commaIndex = statement.find_first_of(":");
    ///if statement contain label
    if(labelIndex!=-1&&commaIndex!=-1) {
        label = statement.substr(labelIndex+5 , (commaIndex-labelIndex-5));
        std::copy(label.begin(),label.end(),pointerStat);
        pointerStat[label.length()]='\0';
        if (stat[labelIndex + 5] != ' ')
            return false;
        ///Check the label variable
        for (int i = 0; i < (int)label.length() - 1; i++) {
            if ((isdigit(pointerStat[i]) || !isdigit(pointerStat[i]) || isalpha(pointerStat[i])) &&
                pointerStat[i + 1] == ' ') {
                for (int j = i + 1; j < (int)label.length() - 1; j++) {
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
        std::copy(label.begin(), label.end(), pointerStat);
        pointerStat[label.length()] = '\0';
        ///Check the label variable
        for (int i = 0; i < (int)label.length() - 1; i++) {
            if ((isdigit(pointerStat[i]) || !isdigit(pointerStat[i]) || isalpha(pointerStat[i])) &&
                pointerStat[i + 1] == ' ') {
                for (int j = i + 1; j < (int)label.length(); j++) {
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

void GotoStatement::execute() {
    string type= getType(statement);
    if (type=="label"){

    } else if (type=="label"){

    }
}



string GotoStatement::getType(string statement) {
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

GotoStatement::GotoStatement(string statmenet, unordered_map<string, double> *variables, map<string, string> *gotoMap)
:Statement(statement,variables) {
    this->gotoMap = gotoMap;
}



