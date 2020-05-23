//
// Created by Zayton on 5/23/2020.
//

#include "LabelStatement.h"

bool LabelStatement::isValid(string satement) {
    int i = satement.find("label");
    
    int length = satement.length();

    for (int i = 0; i <; ++i) {

    }
    return false;
}

void LabelStatement::execute() {

}

LabelStatement::LabelStatement(string statement1, unordered_map<string, double> *variables1, string statement,
                               unordered_map<string, double> *variables, map<string, string> *gotoMap)
        : gotoMap(gotoMap), Statement(statement1, variables1) {

}

