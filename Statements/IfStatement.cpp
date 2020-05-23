#include "IfStatement.h"

bool IfStatement::isValid(const string& statement) {
    int ifCount, colonCount;// counters for ifs and colons, they must be = 1 for valid if statement.
    ifCount = colonCount = 0;
    if (statement.find("if") != std::string::npos)  ifCount++;
    if (statement.find(':') != std::string::npos)   colonCount++;
    return ifCount == 1 && colonCount == 1;
}

void IfStatement::execute() {
        int coloun_Pos, if_Pos;
        coloun_Pos = statement.find(':') != std::string::npos;
        if_Pos = statement.find("if") != std::string::npos;
        //statement.copy(conditionExpression, coloun_Pos - if_Pos - 3 , if_Pos + 3)
        conditionExpression = conditioned_Statement = "";
        if (statement[if_Pos+2] != ' ') throw "there isn't space between if and its condition";
        conditionExpression = statement.substr(if_Pos+3, coloun_Pos-1);
        //TODO: check comment exist if it isn't checked.
        //TODO: create statement object from statement string.
}
