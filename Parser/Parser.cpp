#include "Parser.h"
#include "../Evaluation/Value.h"

Statement *Parser::parse(string statement, unordered_map<string, Value> *map,unordered_map<string,int> *labelMap
        ,unordered_map<int,string> *fileData,int *lineInedx) {
    // Read until you find '#', then stop.
    // The '#' character means the rest of the line is a comment.
    statement = checkLabel(statement,labelMap,lineInedx);
    int lengthBeforeComment = 0;
    while (statement[lengthBeforeComment] != '#' && lengthBeforeComment < (int)statement.length()) {
        lengthBeforeComment++;
    }
    cout<<statement<<endl;
    statement = statement.substr(0, lengthBeforeComment); // substr takes starting index and length.
    StatementType statementType = StatementValidator::validate(statement);
    if (statementType == ASSIGNMENT) {
        return new AssignmentStatement(statement, map);
    } else if (statementType == IF){
        return new IfStatement(statement, map,labelMap,fileData,lineInedx);
    } else if (statementType == GOTO) {
        GotoStatement *gotoStatement = new GotoStatement(statement,map,labelMap,fileData,lineInedx);
        gotoStatement->setLabelName(statement);
        return gotoStatement;
    } else if (statementType == INVALID) {
        return NULL;
    }else {
        throw string("Unexpected StatementType.\n");
    }
    return NULL;
}

string Parser::checkLabel(string statement,unordered_map<string,int> *labelMap,int *lineIndex) {
    char stat[statement.length()];
    char pointerStat[statement.length()];
    string keyWord="label";
    int startWithNumber = 0;
    string label = "";
    int labelIndex = -1;
    int commaIndex = -1;
    labelIndex = statement.find_first_of(keyWord);
    commaIndex = statement.find_first_of(":");
    std::copy(statement.begin(), statement.end(), stat);
    ///if statement contain label
    if (labelIndex != -1 && commaIndex != -1) {
        label = statement.substr(labelIndex + keyWord.length(), (commaIndex - labelIndex - keyWord.length()));
        std::copy(label.begin(), label.end(), pointerStat);
        pointerStat[label.length()] = '\0';
        if (stat[labelIndex + keyWord.length()] != ' ')
            return statement;
        ///Check the label variable
        for (int i = 0; i < (int) label.length() - 1; i++) {
            if ((isdigit(pointerStat[i]) || !isdigit(pointerStat[i]) || isalpha(pointerStat[i])) &&
                pointerStat[i + 1] == ' ') {
                for (int j = i + 1; j < (int) label.length() - 1; j++) {
                    if (pointerStat[j] != ' ') {
                        return statement;
                    }
                }
                break;
            } else if (startWithNumber == 0 && pointerStat[i] != ' ') {
                if (isdigit(pointerStat[i]) && !isalpha(pointerStat[i])) {
                    return statement;
                }
                startWithNumber++;
            }else if (startWithNumber!=0&&(!isalpha(pointerStat[i])&&!isdigit(pointerStat[i])&&pointerStat[i]!='_')){
                return statement;
            }
        }
    }
    statement = statement.substr(commaIndex+1, (statement.length() -commaIndex));
    string savedLabel="";

    label.erase(remove(label.begin(), label.end(), ' '), label.end());

    cout<<"LABEL:"<<label<<"END"<<endl;
    //cout<<"LABEL:"<<*(lineIndex)<<"END"<<endl;
    (labelMap)->insert(pair<string,int>(savedLabel,*lineIndex));
    return statement;
}

