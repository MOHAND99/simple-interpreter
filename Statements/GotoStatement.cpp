//
// Created by Zayton on 5/28/2020.
//

#include "GotoStatement.h"


GotoStatement::GotoStatement(string statement, unordered_map<string, Value> *variables) : Statement(statement,
    variables) {
    labelName =checkGoto(statement);
}

void GotoStatement::execute() {

}

void GotoStatement::setFileData(list<Statement *> *fileData) {
    this->fileData =fileData;
}

void GotoStatement::setLabelData(unordered_map<string, list<Statement *>::iterator> *labelData) {
    this->labelData=labelData;
}



string GotoStatement::checkGoto(string statement) {
    int length = statement.length();
    int gotoIndex =0;
    string variable="";
    if (length > 5 && statement[0] == 'g' && statement[1] == 'o' && statement[2] == 't' && statement[3] == 'o'
        && statement[4] == ' ') {
        gotoIndex = 4;
    } else {
        throw string("Not goto statement");
    }
    variable = statement.substr(gotoIndex+1,length-gotoIndex);
    for (int j = 0; j <= (int) variable.length()-1; j++) {
        if ((isalpha(variable[j]) || isdigit(variable[j]) || variable[j] == '_') && variable[j + 1] == ' ') {
            for (int k = j + 1; k < (int) variable.length(); k++) {
                if (isalpha(variable[k]) || isdigit(variable[k]) || variable[k] == '_')
                    throw string("Varable label is  invalid ");
            }
        }
        if (!isalpha(variable[j]) && !isdigit(variable[j]) && variable[j] != '_'&&variable[j]!=' ') {
            throw string("Varable label is  invalid ");
        }
    }
    variable.erase(remove(variable.begin(), variable.end(), ' '), variable.end()); ;
    return variable;
}
