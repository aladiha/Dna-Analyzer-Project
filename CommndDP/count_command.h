//
// Created by aladinhandoklo on 2/3/21.
//

#ifndef UNTITLED30_COUNT_COMMAND_H
#define UNTITLED30_COUNT_COMMAND_H


#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class CountCommand : public Command{

public:
    explicit CountCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~CountCommand();

private:
    Receiver receiver;

};

#endif //UNTITLED30_COUNT_COMMAND_H
