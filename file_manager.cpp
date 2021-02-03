//
// Created by aladinhandoklo on 1/30/21.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
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

void FileManager::delete_file(const std::string& name) {
    std::string path = prefix + name + ".txt";
    char* str = &path[0];
    remove(str);
}

std::vector<std::string*> FileManager::get_files() {
    DIR *dir; struct dirent *diread;
    std::vector<std::string*> files;

    if ((dir = opendir("../database/")) != 0) {
        while ((diread = readdir(dir)) != 0) {
            files.push_back(new std::string(diread->d_name));
        }
        closedir (dir);
    } else {
        perror ("opendir");
    }
    return files;
}

std::string FileManager::read_with_suffix(std::string* filename) {
    std::string str = prefix + *filename;
    const char* path = &str[0];
    std::ifstream inFile(path, std::ios::in);
    if(inFile) {
        std::string result, seq;
        inFile >> result >> seq;
        std::cout << result << " " << seq << std::endl;
        inFile.close();
        return seq;
    }
    else{
        inFile.close();
        return "";
    }
}
