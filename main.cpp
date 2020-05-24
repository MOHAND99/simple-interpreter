#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Interpretation.h"
#include "FileReader.h"
#include "Statements/GotoStatement.h"
#include "Parser/Parser.h"
using namespace std;

int main() {
//    bool t = GotoStatement::isValid(" label x : y = 10 +5");
//    cout<<t<<endl;
    unordered_map<string, double> *map;
    Parser::parse("label xxx_x:if x>y : x=5",map);
//    Interpretation interpretation;
//    try {
//        FileReader reader("file.txt");
//        while (true)
//            interpretation.process(reader.readNextLine());
//    } catch (string ex) {
//        if (ex != "End of file") cout << ex << endl;
//    }
//    auto map = interpretation.getVariables();
//    for (auto variable : map) {
//        cout << variable.first << " = " << to_string(variable.second) << endl;
//    }
    return 0;
}
