//
// Created by aladinhandoklo on 2/3/21.
//

#ifndef UNTITLED30_CONCAT_COMMAND_H
#define UNTITLED30_CONCAT_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class ConcatCommand : public Command{

public:
    explicit ConcatCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~ConcatCommand();

private:
    Receiver receiver;

};


#endif //UNTITLED30_CONCAT_COMMAND_H
