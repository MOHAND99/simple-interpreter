#include <iostream>
#include <string>
#include "Evaluation/ExpressionEvaluator.h"
#include "FileReader.h"
#include "Interpretation.h"

using namespace std;

int main() {
    FileReader fileReader("file.txt");
    string statement="   ";

    while (statement.size()!=0) {
        Interpretation interpretation;
        statement = fileReader.readNextLine();
        interpretation.process(statement);
    }


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
