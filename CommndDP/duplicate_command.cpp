//
// Created by aladinhandoklo on 2/2/21.
//

#include <iostream>
#include "duplicate_command.h"

void DuplicateCommand::execute(std::vector<std::string> &data) {
    if(data.size() == 3){
        receiver.duplicateAction(data[1], data[2]);
    }
    else{
        std::cout << "invalid duplicate command" << std::endl;
    }
}

DuplicateCommand::DuplicateCommand(Receiver receiver) : receiver(receiver){}

DuplicateCommand::~DuplicateCommand() {}
