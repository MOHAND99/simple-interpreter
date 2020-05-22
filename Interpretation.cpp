#include "Interpretation.h"


unordered_map<string, double> *Interpretation::getMap() {
    return variables;
}

void Interpretation::process(string line) {
    //(*variables)["Q"]=2.5;
    Statement *statement;
    statement = Parser::parse(line, variables);
    if (statement!=NULL){
        (statement)->execute(variables);
    } else{
        cout<<"Error "<<endl;
    }
}

