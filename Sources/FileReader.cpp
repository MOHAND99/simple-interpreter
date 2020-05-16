//
// Created by Mhnd Bshar on 5/16/2020.
//

#include "../Headers/FileReader.h"
#include <fstream>
#include <iostream>

FileReader::FileReader(string filename) {
    ifstream file;
    file.open(filename);
    checkExist(file);
    read(file);
    file.close();
}

void FileReader::checkExist(ifstream file) {
    if(file.fail()){
        cout<<"file isn't existed"<<endl;
        exit(EXIT_FAILURE);
    }
}

void FileReader::read(ifstream file) {
    string  line;
    while(getline(file, line)){
        Evaluate(line);
    }
}

