#ifndef SIMPLE_INTERPRETER_INTERPRETATION_H
#define SIMPLE_INTERPRETER_INTERPRETATION_H

#include <bits/stdc++.h>
#include <string>
#include "Evaluation/Value.h"

using namespace std;


class Interpretation {
private:
    unordered_map<string, Value> variables;
    unordered_map<int,string> fileData;
    unordered_map<string,int> labelMap;
    int lineIndex;

public:
    /*
     * Parse the line, then call execute on the returned statement.
     */
    Interpretation();
    void process(string line);
    unordered_map<string, Value> getVariables() const;
    int getLine();
    void setLine(int *lineIndex);
    int incrementLineIndex();
    void setVariablesMap(unordered_map<string, Value> *variables);
    void setfFileDataMap(unordered_map<int,string> *fileData);
    void setLabelMap(unordered_map<string, int> *labelMap);
    unordered_map<string, Value> *getVariables();

};


#endif //SIMPLE_INTERPRETER_INTERPRETATION_H
