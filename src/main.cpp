#include <iostream>
#include "main.hpp"
#include <fstream>
#include <sstream>

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

std::string readFile(const std::string path) {
    std::string string;
    std::ifstream file(path, std::ios::in | std::ios::binary);
    while(getline(file, line)) {
        string += line + "\n";
    }
    file.close();
    return string;
}

void onlyReadFile(const std::string path) {
    std::ifstream file(path, std::ios::in | std::ios::binary);
    while(getline(file, line)) { }
}

void writeFile(const std::string content, const std::string dest) {
    std::ofstream file(dest, std::ios::out | std::ios::trunc);
    file << content;
    file.close();
}


void formatElapsedTime(const std::chrono::duration<double> time, const std::string message) {
    std::chrono::duration<double> elapsed_seconds = time;
    std::cout << "Elapsed " << std::setprecision(25) << elapsed_seconds.count() << "s to " << message << std::endl;
}



int main() {
    // Config
    askForAVariable("Please enter the source path: ", &sourceFilePath);
    sourceFileSize = getFileSize(sourceFilePath);
    if (sourceFileSize == false) {
        std::cout << "Could not read source file" << std::endl;
        return 1;
    }
    askForAVariable("Please enter the destination path (where the files will be copied to): ", &destFilePath);
    askForAVariable("Please enter the number of times you want to perform the writing test: ", &writingTestTime);
    askForAVariable("Please enter the number of times you want to perform the reading test: ", &readingTestTime);

    // Perform writing test
    sourceContent = readFile(sourceFilePath);
    int writingtests = std::stoi(writingTestTime);
    auto start = std::chrono::system_clock::now();
    for(int x = 0; x < writingtests; x++) {
        writeFile(sourceContent, destFilePath);
    }
    auto end = std::chrono::system_clock::now();
    formatElapsedTime(end-start, "write " + writingTestTime + " times " + std::to_string(sourceFileSize) + " bytes");

    // Perform reading test
    auto readStart = std::chrono::system_clock::now();
    int readingtests = std::stoi(readingTestTime);
    for(int x = 0; x < readingtests; x++) {
        onlyReadFile(destFilePath);
    }
    auto endStart = std::chrono::system_clock::now();
    formatElapsedTime(endStart-readStart, "read " + readingTestTime + " times " + std::to_string(sourceFileSize) + " bytes");
    return 0;
}