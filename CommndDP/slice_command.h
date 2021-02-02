//
// Created by aladinhandoklo on 2/2/21.
//

#ifndef UNTITLED30_SLICE_COMMAND_H
#define UNTITLED30_SLICE_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class SliceCommand : public Command{

public:
    explicit SliceCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~SliceCommand();

private:
    Receiver receiver;

};

#endif //UNTITLED30_SLICE_COMMAND_H
