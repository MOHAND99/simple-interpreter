#include <iostream>
#include <string>
#include "Interpretation.h"
#include "FileReader.h"
#include "Statements/GotoStatement.h"
using namespace std;

int main() {
    bool t = GotoStatement::isValid(" label x : y = 10 +5");
    cout<<t<<endl;
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
