#include "Interpretation.h"
#include "Parser/Parser.h"

void Interpretation::process(string line) {
    Statement *statement = Parser::parse(line, &variables,&labelMap,&fileData,&lineIndex);

    if (statement != NULL) {
        statement->execute();
        fileData.emplace(lineIndex,line);
        lineIndex=incrementLineIndex();

    }

}

unordered_map<string, Value> Interpretation::getVariables() const {
    return variables;
}

int Interpretation::getLine() {
    return lineIndex;
}

void Interpretation::setLine(int lineIndex) {
    lineIndex=lineIndex;
}

int Interpretation::incrementLineIndex() {
    return lineIndex+1;
}

Interpretation::Interpretation() {
    lineIndex=1;
}

