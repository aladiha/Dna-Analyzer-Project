//
// Created by aladinhandoklo on 1/30/21.
//

#include <fstream>
#include <iostream>
#include "file_manager.h"

void FileManager::write_to_file(const char* fileName, const char* data) {
    std::ofstream outFile(fileName, std::ios::app);
    outFile << data << std::endl;
    outFile.close();
    std::cout << data;
}

std::string FileManager::read_from_file(const char *fileName) {
    std::ifstream inFile(fileName, std::ios::in);
    std::string al;
    inFile >> al;
    std::cout << al;
}
