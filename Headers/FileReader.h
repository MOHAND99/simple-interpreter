//
// Created by Mhnd Bshar on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_FILEREADER_H
#define SIMPLE_INTERPRETER_FILEREADER_H
#include <fstream>

using namespace std;

class FileReader {
private:
    void checkExist(ifstream file);
    void read(ifstream file);
public:
    FileReader(string filename);
};

#endif //SIMPLE_INTERPRETER_FILEREADER_H
