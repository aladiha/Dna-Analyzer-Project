//
// Created by aladinhandoklo on 2/3/21.
//

#ifndef UNTITLED30_PAIR_COMMAND_H
#define UNTITLED30_PAIR_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"
#include "receiver.h"

class PairCommand : public Command{

public:
    explicit PairCommand(Receiver receiver);
    void execute(std::vector<std::string>& data);
    ~PairCommand();

private:
    Receiver receiver;

};

#endif //UNTITLED30_PAIR_COMMAND_H
