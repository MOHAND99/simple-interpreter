//
// Created by Zayton on 5/23/2020.
//

#include "GotoStatement.h"

bool GotStatement::isValid(string statement) {
    char stat[statement.length()];
    string label="";
    char pointerStat[statement.length()];
    std::copy(statement.begin(),statement.end(),stat);
    int labelIndex =-1;
    int gotoStat=-1;
    int commaIndex =-1;
    int space=0;
    labelIndex = statement.find_first_of("label");
    gotoStat = statement.find_first_of("goto");
    commaIndex = statement.find_first_of(":");
    label = statement.substr(labelIndex+5 , (commaIndex-labelIndex-5));
    std::copy(label.begin(),label.end(),pointerStat);
    pointerStat[label.length()]='\0';
    if (stat[labelIndex+5]!=' '||isdigit(stat[space]))
        return false;
    for (int i = 0; i <label.length()-1 ; i++) {

        if ((isdigit(pointerStat[i])||!isdigit(pointerStat[i])||isalpha(pointerStat[i]))&&pointerStat[i+1]==' '){
            for (int j = i+1; j <label.length()-1; j++) {
                if (pointerStat[j]!=' '){
                    return false;
                }
            }
            break;
        }
    }


    return true;
}

void GotStatement::execute() {

}

GotStatement::GotStatement(string statement1, unordered_map<string, double> *variables1, string statement,
                               unordered_map<string, double> *variables, map<string, string> *gotoMap)
        : gotoMap(gotoMap), Statement(statement1, variables1) {

}

