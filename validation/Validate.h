//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_VALIDATE_H
#define SIMPLE_INTERPRETER_VALIDATE_H
#include <iostream>
#include "string"
#include <list>
#include "../Classify.h"

using namespace std;

class Validate {
private:
     string statementList;///List received from the file reader
     list<string> validStatement;///statement after validate to sent it to classify class
     Classify classify ;
public:
    Validate(string statement);
    void validationOfSatement(string statement);///start to validate every loaded statement from the list
    bool checkVariablePalce(string statement);///check the variable palce if more than one on the left
    bool checkFunction(string statement);///Check for the function words {function , endfunction}
    bool checkIfStatement(string statement);///check for if word
    bool checkComment(string statement);///check for comment , use these method in other check method to check for comment
    bool checkGoToStatement(string statement);///check go to statement

};


#endif //SIMPLE_INTERPRETER_VALIDATE_H
