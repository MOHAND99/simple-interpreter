#include "Parser.h"
#include "../Evaluation/Value.h"

Statement *Parser::parse(string statement, unordered_map<string, Value> *map,unordered_map<string,int> *labelMap
        ,unordered_map<int,string> *fileData,int *lineInedx) {
    // Read until you find '#', then stop.
    // The '#' character means the rest of the line is a comment.
    statement = checkLabel(statement, labelMap, lineInedx);
    int lengthBeforeComment = 0;
    while (statement[lengthBeforeComment] != '#' && lengthBeforeComment < (int) statement.length()) {
        lengthBeforeComment++;
    }
    cout << statement << endl;
    statement = statement.substr(0, lengthBeforeComment); // substr takes starting index and length.
    StatementType statementType = StatementValidator::validate(statement);
    if (statementType == ASSIGNMENT) {
        return new AssignmentStatement(statement, map);
    } else if (statementType == IF) {
        return new IfStatement(statement, map, labelMap, fileData, lineInedx);
    } else if (statementType == GOTO) {
        GotoStatement *gotoStatement = new GotoStatement(statement, map, labelMap, fileData, lineInedx);
        gotoStatement->setLabelName(statement);
        return gotoStatement;
    } else if (statementType == INVALID) {
        return NULL;
    }
}


string Parser::checkLabel(string statement,unordered_map<string,int> *labelMap,int *lineIndex) {
    string keyWord="label";
    string label = "";
    int startWithNumber = 0;
    int labelIndex = -1;
    int commaIndex = -1;
    labelIndex = statement.find_first_of(keyWord);
    commaIndex = statement.find_first_of(":");
    ///if statement contain label
    if (labelIndex != -1 && commaIndex != -1) {
        label = statement.substr(labelIndex + keyWord.length(), (commaIndex - labelIndex - keyWord.length()));
        label[label.length()] = '\0';
        if (statement[labelIndex + keyWord.length()] != ' ')
            return statement;
        ///Check the label variable
        for (int i = 0; i < (int) label.length() - 1; i++) {
            if ((isdigit(label[i]) || !isdigit(label[i]) || isalpha(label[i])) &&
                    label[i + 1] == ' ') {
                for (int j = i + 1; j < (int) label.length() - 1; j++) {
                    if (label[j] != ' ') {
                        return statement;
                    }
                }
                break;
            } else if (startWithNumber == 0 && label[i] != ' ') {
                if (isdigit(label[i]) && !isalpha(label[i])) {
                    return statement;
                }
                startWithNumber++;
            }else if (startWithNumber!=0&&(!isalpha(label[i])&&!isdigit(label[i])&&label[i]!='_')){
                return statement;
            }
        }
    }
    if (labelIndex==-1||commaIndex==-1)
        return statement;
    statement = statement.substr(commaIndex+1, (statement.length() -commaIndex));
    label.erase(remove(label.begin(), label.end(), ' '), label.end());
    cout<<"LABEL:"<<label<<"END"<<endl;
    //cout<<"LABEL:"<<*(lineIndex)<<"END"<<endl;
    (labelMap)->insert(pair<string,int>(label,*lineIndex));
    return statement;
}

