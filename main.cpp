#include <iostream>
#include <string>
#include "ExpressionEvaluator.h"
using namespace std;

int main() {
    //5 - -(-3 -  +(2))
    //7 - (--5)
    //(--.5)*(-(-0.5)   )     + +10 / -(2)
    //55*55/22+5
    //55--5
    string  s = "(--.5)*(-(-0.5)   )     + +10 / -(2)";
    cout<<4 - -4<<endl;
    ExpressionEvaluator evaluator = ExpressionEvaluator(s);
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
