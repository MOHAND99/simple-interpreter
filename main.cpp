#include <iostream>
#include <string>
#include "ExpressionEvaluator.h"
using namespace std;

int main() {
    ExpressionEvaluator evaluator = ExpressionEvaluator("(-2+4)*(-5**5)");
    evaluator.addSpace();
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
    return 0;
}
