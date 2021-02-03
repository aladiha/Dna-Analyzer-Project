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
    void replaceAction(const std::string& name, int index, const std::string& newLetter);
    void concatAction(const std::string &basicString,const std::string &basicString1,const std::string &basicString2);
    void pairAction(const std::string &basicString, const std::string &basicString1);
    void findAction(const std::string &basicString,const std::string &basicString1);
    void countAction(const std::string &basicString,const std::string &basicString1);

    void HelpAction();

    void listAction();
};


#endif //UNTITLED30_RECEIVER_H
