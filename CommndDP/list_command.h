//
// Created by aladinhandoklo on 2/3/21.
//

#ifndef UNTITLED30_LIST_COMMAND_H
#define UNTITLED30_LIST_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class ListCommand : public Command{

public:
    explicit ListCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~ListCommand();

private:
    Receiver receiver;

};

#endif //UNTITLED30_LIST_COMMAND_H
