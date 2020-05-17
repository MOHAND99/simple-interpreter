#include <iostream>
#include <string>
#include "Statements/AssignmentStatement.h"

using namespace std;

int main() {
//    FileReader reader("Src.txt");
//    Interpretation compilation;
//    string line;
//    while (line = reader.readLine()) {
//        Variable variable = compilation.process(line);
//        /*
//         * Internally, the process method will parse the instruction, evaluate the expression, and
//         * return the variable name and its value (Variable can be a struct).
//         */
//        // TODO: Add the variable to BST and heap.
//
//    }
    cout << AssignmentStatement::isValid("X=5");
    cout << AssignmentStatement::isValid(" XYA  =    5  ");
    cout << AssignmentStatement::isValid(" 1X  =    5  ");
    cout << AssignmentStatement::isValid("1X  =    5  ");
    cout << AssignmentStatement::isValid("1  =    5  ");
    cout << AssignmentStatement::isValid("X Y  =    5  ");
    cout << AssignmentStatement::isValid("  X+Y  =    5  ");
    return 0;
}
