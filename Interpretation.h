#ifndef SIMPLE_INTERPRETER_INTERPRETATION_H
#define SIMPLE_INTERPRETER_INTERPRETATION_H

#include <bits/stdc++.h>
#include <string>

using namespace std;
class lineData {
public:int lineNumber;
        string lable;
};
class Interpretation {
private:
    unordered_map<string, double> variables;
    map<lineData,string> gotoMap;
public:
    /*
     * Parse the line, then call execute on the returned statement.
     */
    void process(string line);
    unordered_map<string, double> getVariables() const;
};


#endif //SIMPLE_INTERPRETER_INTERPRETATION_H
