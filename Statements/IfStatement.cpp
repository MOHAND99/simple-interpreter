#include "IfStatement.h"

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
        int coloun_Pos, if_Pos;
        coloun_Pos = statement.find(':') != std::string::npos;
        if_Pos = statement.find("if") != std::string::npos;
        conditionExpression = conditioned_Statement = "";
        conditionExpression = statement.substr(if_Pos+3, coloun_Pos-1);
        //TODO: check comment exist if it isn't checked.
        //TODO: create statement object from statement string.
}

IfStatement::IfStatement(const string &statement, unordered_map<string, &variables> string) {

}

IfStatement::IfStatement(const string &statement, const unordered_map<string, &variables, const string &

conditionExpression,
const Statement &conditioned_Statement
):
Statement(statement, variables
),

conditionExpression (conditionExpression), conditioned_Statement(conditioned_Statement) {

}
