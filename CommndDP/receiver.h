//
// Created by aladinhandoklo on 1/27/21.
//

#ifndef UNTITLED30_RECEIVER_H
#define UNTITLED30_RECEIVER_H


#include <string>
#include "../file_manager.h"

class Receiver {

public:
    void newAction(const std::string& sequence,const std::string& name);
    void loadAction(const std::string& name);
    void duplicateAction(const std::string& name, const std::string& secondName);
    void sliceAction(const std::string& name, int startIndex, int endIndex, const std::string& secondName);
};


#endif //UNTITLED30_RECEIVER_H
