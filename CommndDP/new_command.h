//
// Created by aladinhandoklo on 1/27/21.
//

#ifndef UNTITLED30_NEW_COMMAND_H
#define UNTITLED30_NEW_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class NewCommand : public Command{

    public:
          explicit NewCommand(Receiver receiver);
          void execute(std::vector<std::string>& data);
          ~NewCommand();
private:
    Receiver receiver;

};



#endif //UNTITLED30_NEW_COMMAND_H
