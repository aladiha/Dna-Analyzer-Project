//
// Created by aladinhandoklo on 1/30/21.
//

#ifndef UNTITLED30_FILE_MANAGER_H
#define UNTITLED30_FILE_MANAGER_H


#include <string>

class FileManager {

public:
    static void write_to_file(const std::string& fileName, const std::string& data);
    static std::string read_from_file(const std::string& fileName);
    static void delete_file(const std::string &basicString);

private:
    static const std::string prefix;

};


#endif //UNTITLED30_FILE_MANAGER_H
