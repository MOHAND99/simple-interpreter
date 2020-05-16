//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_FILEREADER_H
#define SIMPLE_INTERPRETER_FILEREADER_H

#include <string>

class FileReader {
private:
    string fileName;
public:
    FileReader(string fileName);
    void readFile();
};


#endif //SIMPLE_INTERPRETER_FILEREADER_H
