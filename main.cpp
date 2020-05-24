#include <iostream>
#include <string>
#include "Interpretation.h"
#include "FileReader.h"
#include "Parser/Parser.h"
#include "Statements/Statement.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
//    unordered_map<string, Value> variables;
//    unordered_map<int,string> fileData;
//    unordered_map<string,int> labelMap;
//    int lineIndex=5;
//    Statement *statement  = Parser::parse("label x : y=10+50",&variables,&labelMap,&fileData,&lineIndex);
    Interpretation interpretation;
    try {
        FileReader reader("file.txt");
        while (true)
            interpretation.process(reader.readNextLine());
    } catch (string ex) {
        if (ex != "End of file") cout << ex << endl;
    } catch (char const* ex) {
        cout << ex << endl;
    }
    auto map = interpretation.getVariables();
    for (auto variable : map) {
        cout << variable.first << " = " << variable.second.toString() << endl;
    }

    return 0;
}
