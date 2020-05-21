#ifndef SIMPLE_INTERPRETER_PARSER_H
#define SIMPLE_INTERPRETER_PARSER_H

#include <string>
#include "../Statements/AssignmentStatement.h"
#include "StatementValidator.h"

using namespace std;

class Parser {
public:
    static Statement* parse(string statement, unordered_map<string,double> *variables);
    /*
     * The `parse` method should validate the provided statement by using the StatementValidator.
     * After knowing its type, return a pointer to object of Statement.
     * If the statement is INVALID, return NULL.
     * The Parser behaves like a factory of Statement.
     */
private:
    string static removeComment(string statment);
};


#endif //SIMPLE_INTERPRETER_PARSER_H
