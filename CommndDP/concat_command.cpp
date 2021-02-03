//
// Created by aladinhandoklo on 2/3/21.
//

#include <iostream>
#include "concat_command.h"


void ConcatCommand::execute(std::vector<std::string> &data) {
    if(data.size() == 4){
        receiver.concatAction(data[1], data[2], data[3]);
    }
    else{
        std::cout << "invalid concat command" << std::endl;
    }
}

ConcatCommand::ConcatCommand(Receiver receiver) : receiver(receiver){}

ConcatCommand::~ConcatCommand() {}