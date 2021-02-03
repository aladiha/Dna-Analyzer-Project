//
// Created by aladinhandoklo on 2/3/21.
//

#ifndef UNTITLED30_FIND_COMMAND_H
#define UNTITLED30_FIND_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class FindCommand : public Command{

public:
    explicit FindCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~FindCommand();

private:
    Receiver receiver;

};


#endif //UNTITLED30_FIND_COMMAND_H
