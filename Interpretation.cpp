#include "Interpretation.h"
#include "Parser/Parser.h"

void Interpretation::process(string line) {
    Statement *statement = Parser::parse(line, &variables);
    if (statement != NULL) {
        statement->execute();
        delete statement;
    }

}

unordered_map<string, Value> Interpretation::getVariables() const {
    return variables;
}
