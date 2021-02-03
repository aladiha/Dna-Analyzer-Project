//
// Created by aladinhandoklo on 2/3/21.
//

#include <iostream>
#include "pair_command.h"

PairCommand::PairCommand(Receiver receiver) : receiver(receiver){}

void PairCommand::execute(std::vector<std::string>& data) {
    if(data.size() == 3){
        receiver.pairAction(data[1], data[2]);
    }
    else{
        std::cout << "invalid pair command" << std::endl;
    }
}

PairCommand::~PairCommand() {}