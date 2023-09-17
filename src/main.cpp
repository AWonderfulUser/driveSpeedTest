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

int main() {
    std::cout << "Please enter the path of the file you want to copy: ";
    std::cin >> sourceFilePath;
    sourceFileSize = getFileSize();
    if (sourceFileSize == false) {
        std::cout << "Could not read source file" << std::endl;
        return 1;
    }
    return 0;
}