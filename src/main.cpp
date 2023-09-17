#include <iostream>
#include "main.hpp"
#include <fstream>

std::ifstream::pos_type getFileSize(const std::string filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    if(in.is_open()) {
        return in.tellg(); 
    } else {
        return false;
    }
}

void askForAVariable(const std::string sentence, std::string* path) {
    std::cout << sentence;
    std::cin >> *path;
}

std::string readFile(std::string path) {
    std::string string;
    std::ifstream file(path, std::ios::in | std::ios::binary);
    while(getline(file, line)) {
        string += line + "\n";
    }
    file.close();
    return string;
}

int main() {
    askForAVariable("Please enter the source path: ", &sourceFilePath);
    sourceFileSize = getFileSize(sourceFilePath);
    if (sourceFileSize == false) {
        std::cout << "Could not read source file" << std::endl;
        return 1;
    }
    askForAVariable("Please enter the destination path: ", &destFilePath);
    std::string sourceContent = readFile(sourceFilePath);

    return 0;
}