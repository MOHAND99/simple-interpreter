#include <iostream>
#include <string>
#include "Interpretation.h"
#include "FileReader.h"
#include "Parser/Parser.h"
#include "Statements/Statement.h"
#include <bits/stdc++.h>

using namespace std;
string checkLabel(string statement){
    int comma=0;
    int label=0;
    int length = statement.length();
    string variable;
    for (int i=0; i<length;i++) {
        if (i==0&&statement[i]=='l'&&statement[i+1]=='a'&&statement[i+2]=='b'&&statement[i+3]=='e'
            &&statement[i+4]=='l'&&statement[i+5]==' '){
            i=5;
            label=i;
        }else if (statement[i]==':') {
            comma=i;
            break;
        }
    }
    if (comma==0||label==0){
        return statement;
    }
    variable = statement.substr(label+1,comma-label-1);
    cout<<"Var : "<<variable<<endl;
    for (int j = 0; j <=variable.length(); j++) {
        if (isalpha(variable[j])||isdigit(variable[j])||variable[j]=='_'&&variable[j+1]==' '){
            for (int k = j+1; k <variable.length() ; k++) {
                if (isalpha(variable[k])||isdigit(variable[k])||variable[k]=='_')
                    return statement;
            }
        }
        if (!isalpha(variable[j])&&!isdigit(variable[j])&&variable[j]!='_'){
            return statement;
        }
    }
    ///Trim space from the variable
    ///Then Add the statement to the List
    ///Then Store it in the map
    return statement.substr(comma+1,length-comma);
}
int main() {
//    unordered_map<string, Value> variables;
//    unordered_map<int,string> fileData;
//    unordered_map<string,int> labelMap;
//    int lineIndex=5;
//    Statement *statement  = Parser::parse("label x : y=10+50",&variables,&labelMap,&fileData,&lineIndex);
    Interpretation interpretation;
    cout<<checkLabel("label :y=10+55 ")<<endl;
    cout<<"----------------------------------"<<endl;
//    try {
//        FileReader reader("file.txt");
//        while (true)
//            interpretation.process(reader.readNextLine());
//    } catch (string ex) {
//        if (ex != "End of file") cout << ex << endl;
//    } catch (char const* ex) {
//        cout << ex << endl;
//    }
//    auto map = interpretation.getVariables();
//    for (auto variable : *map) {
//        cout << variable.first << " = " << variable.second.toString() << endl;
//    }

    return 0;
}
