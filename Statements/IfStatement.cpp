//
// Created by Mhnd Bshar on 5/23/2020.
//

#include "IfStatement.h"

bool IfStatement::isValid(string statement) {
    int ifCount, colonCount;// counters for ifs and colons, they must be = 1 for valid if statement
    ifCount = colonCount = 0;
    if (statement.find("if") != std::string::npos)  ifCount++;
    if (statement.find(":") != std::string::npos)   colonCount++;
    if(ifCount == 1 && colonCount == 1) return true;
    return false;
}
