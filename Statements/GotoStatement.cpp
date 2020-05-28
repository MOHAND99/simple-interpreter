//
// Created by Zayton on 5/28/2020.
//

#include "GotoStatement.h"


GotoStatement::GotoStatement(string statement, unordered_map<string, Value> *variables) : Statement(statement,
                                                                                                    variables) {

}

void GotoStatement::execute() {

}
