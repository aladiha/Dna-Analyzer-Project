//
// Created by aladinhandoklo on 2/3/21.
//

#ifndef UNTITLED30_HELP_COMMAND_H
#define UNTITLED30_HELP_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class HelpCommand : public Command{

public:
    explicit HelpCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~HelpCommand();

private:
    Receiver receiver;

};

#endif //UNTITLED30_HELP_COMMAND_H
