//
// Created by Mhnd Bshar on 5/16/2020.
//

#include "../Headers/FileReader.h"
#include <fstream>
#include <iostream>


FileReader::FileReader(string filename) {
    if (!file.is_open())
        file.open(filename);
    checkExist();
}

void FileReader::checkExist() {
    if(file.fail()){
        cout<<"file isn't existed"<<endl;
        exit(EXIT_FAILURE);
    }
}

string FileReader::read() {
    string line;
    getline(file, line))
    return line;
}

