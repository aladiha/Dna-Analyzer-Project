//
// Created by aladinhandoklo on 2/2/21.
//

#ifndef UNTITLED30_LOAD_COMMAND_H
#define UNTITLED30_LOAD_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class LoadCommand : public Command{

public:
    explicit LoadCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~LoadCommand();

private:
    Receiver receiver;

};


#endif //UNTITLED30_LOAD_COMMAND_H
