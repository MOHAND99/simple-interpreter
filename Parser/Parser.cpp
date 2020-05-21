#include "Parser.h"


string Parser::removeComment(string statement) {
    string st="";
    int i=0;
     i = statement.find("#");
    if (i>0) {
        st=statement.substr(0,i);
    } else{
        return statement;
    }
    return st;
}

Statement* Parser::parse(string statement, unordered_map<string, double> *variables) {
    string statWithoutComment = removeComment(statement);
    StatementType  type = StatementValidator::validate(statWithoutComment);
    if(type==ASSIGNMENT){
        AssignmentStatement *assignmentStatement = new AssignmentStatement(statWithoutComment,variables);
        return assignmentStatement;
    } else if (type==INVALID){
        std::cout<<"Invalid Statement"<<endl;
    }

    return NULL;
}


