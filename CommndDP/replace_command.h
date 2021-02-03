//
// Created by aladinhandoklo on 2/2/21.
//

#ifndef UNTITLED30_REPLACE_COMMAND_H
#define UNTITLED30_REPLACE_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class ReplaceCommand : public Command{

public:
    explicit ReplaceCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~ReplaceCommand();

private:
    Receiver receiver;

};

#endif //UNTITLED30_REPLACE_COMMAND_H
