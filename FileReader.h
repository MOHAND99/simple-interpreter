//
// Created by Zayton on 5/16/2020.
//

#ifndef SIMPLE_INTERPRETER_FILEREADER_H
#define SIMPLE_INTERPRETER_FILEREADER_H

#include <string>
#include <list>
using namespace std;
class FileReader {
private:
    string fileName;
    list<string> statement; //linked list to store the file line by line
public:
    FileReader(string fileName); //take the file name from the main.cpp
    string readFile(); //read the file line by and store it in list statement

};


#endif //SIMPLE_INTERPRETER_FILEREADER_H
