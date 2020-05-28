#include "Interpretation.h"
#include "Parser/Parser.h"

void Interpretation::process(string line) {
    // Ignore leading whitespaces.
    string labelName ="";
    char commentSymbol = '#';
    int startingIndex = 0;
    while (line[startingIndex] == ' ') startingIndex++;
    // Read until a comment is encountered.
    int endingIndex = startingIndex;
    while (endingIndex < (int) line.size() && line[endingIndex] != commentSymbol) endingIndex++;
    line = checkLabel(line, &labelName);

    // If line is empty, return.
    if (startingIndex == endingIndex) return;

    // Get the line without the leading whitespaces and without the comment.
    line = line.substr(startingIndex, endingIndex - startingIndex);
    Statement *statement = Parser::parse(line, &variables);
    cout << statement << endl;
    fileData.push_back(statement);
    if ((labelName).length() != 0) {
        auto  iter = labelData.find(labelName);
        try {
            if (iter == labelData.end()) {
                list<Statement *>::iterator it = fileData.end();
                labelData.insert(pair<string, list<Statement *>::iterator>(labelName, it));
            }
        }catch (...){
            cout<<"The label Variable has been defined befor"<<endl;
        }


    }
    if (typeid(statement)== typeid(GotoStatement)){
        ((GotoStatement&&)statement).setFileData(&fileData);
        ((GotoStatement&&)statement).setLabelData(&labelData);
    }
    statement->execute();


}

string Interpretation::checkLabel(string statement, string *labelName) {
    int comma = 0;
    int label = 0;
    int length = statement.length();
    string variable;
    if (length > 5 && statement[0] == 'l' && statement[1] == 'a' && statement[2] == 'b' && statement[3] == 'e'
        && statement[4] == 'l' && statement[5] == ' ') {
        label = 5;
    } else {
        return statement;
    }
    for (int i = 5; i < length; i++) {
        if (statement[i] == ':') {
            comma = i;
            break;
        }
    }
    if (comma == 0) {
        return statement;
    }
    variable = statement.substr(label + 1, comma - label - 1);
    cout << "Var : " << variable << endl;
    for (int j = 0; j <= (int) variable.length()-1; j++) {
        if ((isalpha(variable[j]) || isdigit(variable[j]) || variable[j] == '_') && variable[j + 1] == ' ') {
            for (int k = j + 1; k < (int) variable.length(); k++) {
                if (isalpha(variable[k]) || isdigit(variable[k]) || variable[k] == '_')
                    throw string("Invalid Variable");
            }
        }
        if (!isalpha(variable[j]) && !isdigit(variable[j]) && variable[j] != '_'&&variable[j]!=' ') {
            throw string("Invalid Variable");
        }
    }
    ///Trim space from the variable
    variable.erase(remove(variable.begin(), variable.end(), ' '), variable.end());
    *labelName = variable;
    return statement.substr(comma + 1, length - comma);
}

unordered_map<string, Value> Interpretation::getVariables() const {
    return variables;
}
