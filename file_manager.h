//
// Created by aladinhandoklo on 1/30/21.
//

#ifndef UNTITLED30_FILE_MANAGER_H
#define UNTITLED30_FILE_MANAGER_H


#include <string>

class FileManager {
    static void write_to_file(const char* fileName, const char* data);
    static std::string read_from_file(const char* fileName);
};


#endif //UNTITLED30_FILE_MANAGER_H
