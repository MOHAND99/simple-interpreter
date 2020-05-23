#include "IfStatement.h"
#include "../Parser/Parser.h"

bool IfStatement::isValid(const string& statement) {
    int ifCount, colonCount, if_Pos;// counters for ifs and colons, they must be = 1 for valid if statement.
    ifCount = colonCount = 0;
    while ((if_Pos = statement.find("if")) != std::string::npos)  {
        if (statement[if_Pos+2] != ' ') throw "there isn't space between if and its condition";
        ifCount++;
    }
    while (statement.find(':') != std::string::npos)   colonCount++;
    return ifCount == colonCount;
}

void IfStatement::execute() {
        //TODO: call evaluator to check if statement is true, then check this second if
        if(conditioned_Statement) conditioned_Statement->execute();
}

IfStatement::IfStatement(const string &statement, unordered_map<string, double> *variables) : Statement(statement,
                                                                                                        variables) {
    int coloun_Pos, if_Pos;
    coloun_Pos = statement.find(':') != std::string::npos;
    if_Pos = statement.find("if") != std::string::npos;
    conditionExpression = "";
    conditionExpression = statement.substr(if_Pos+3, coloun_Pos-1);
    conditioned_Statement = Parser::parse(statement.substr(coloun_Pos+1), variables);
}

