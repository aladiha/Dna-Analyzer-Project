//
// Created by aladinhandoklo on 1/30/21.
//

#include <fstream>
#include <iostream>
#include "file_manager.h"

const std::string FileManager::prefix = "../database/";

void FileManager::write_to_file(const std::string& sequence, const std::string& fileName) {
    std::string path = prefix + fileName + ".txt";
    const char* str = &path[0];
    std::fstream outFile;
    outFile.open(str, std::ios::in | std::ios::out | std::ios::app);
    outFile << fileName + ": " + sequence << std::endl;
    outFile.close();
}

std::string FileManager::read_from_file(const std::string& fileName) {
    std::string path = prefix + fileName + ".txt";
    const char* str = &path[0];
    std::ifstream inFile(str, std::ios::in);
    if(inFile) {
        std::string result, seq;
        inFile >> result >> seq;
        std::cout << result << " " << seq << std::endl;
        inFile.close();
        return seq;
    }
    else{
        return "";
    }
}
