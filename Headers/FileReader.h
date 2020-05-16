//
// Created by Mhnd Bshar on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_FILEREADER_H
#define SIMPLE_INTERPRETER_FILEREADER_H
#include <fstream>

using namespace std;

class FileReader {
private:
    fstream file;
    void checkExist();
public:
    FileReader(string filename);
    string read();
};

#endif //SIMPLE_INTERPRETER_FILEREADER_H
