#include "Interpretation.h"
#include "Parser/Parser.h"

void Interpretation::process(string line) {
    Statement *statement = Parser::parse(line, &variables,&labelMap,&fileData,&lineIndex);

    if (statement != NULL) {
        fileData.emplace(lineIndex,line);
        statement->execute();
        lineIndex=incrementLineIndex();

    }

}

unordered_map<string, Value> Interpretation::getVariables() const {
    return variables;
}

int Interpretation::getLine() {
    return lineIndex;
}

void Interpretation::setLine(int *lineIndex) {
    this->lineIndex=*lineIndex;
}

int Interpretation::incrementLineIndex() {
    return lineIndex+1;
}

Interpretation::Interpretation() {
    lineIndex=1;
}

void Interpretation::setVariablesMap(unordered_map<string, Value> *variables) {
    this->variables=*variables;
}

void Interpretation::setfFileDataMap(unordered_map<int, string> *fileData) {
    this->fileData=*fileData;
}

void Interpretation::setLabelMap(unordered_map<string, int> *labelMap) {
    this->labelMap=*labelMap;
}

