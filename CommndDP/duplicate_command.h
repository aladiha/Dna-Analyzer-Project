//
// Created by aladinhandoklo on 2/2/21.
//

#ifndef UNTITLED30_DUPLICATE_COMMAND_H
#define UNTITLED30_DUPLICATE_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class DuplicateCommand : public Command{

public:
    explicit DuplicateCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~DuplicateCommand();

private:
    Receiver receiver;

};



#endif //UNTITLED30_DUPLICATE_COMMAND_H
