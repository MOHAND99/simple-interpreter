#include "Interpretation.h"


unordered_map<string, double> *Interpretation::getMap() {
    return variables;
}

void Interpretation::process(string line) {
    Statement *assignmentStatement;
    assignmentStatement = Parser::parse(line, variables);
    if (assignmentStatement!=NULL){
        (assignmentStatement)->execute(variables);
    } else{
        cout<<"Error "<<endl;
    }
}
