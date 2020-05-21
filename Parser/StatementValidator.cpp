#include "StatementValidator.h"

StatementType StatementValidator::validate(string statement) {
    bool  assig = AssignmentStatement::isValid(statement);
    if (assig)
        return ASSIGNMENT;
    return INVALID;
}
