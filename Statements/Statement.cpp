#include "Statement.h"

Statement::Statement(string statement, unordered_map<string, Value> *variables) {
    this->statement = statement;
    this->variables = variables;
}

const string &Statement::getStatement() const {
    return statement;
}


