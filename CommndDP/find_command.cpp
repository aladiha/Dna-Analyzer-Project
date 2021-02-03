//
// Created by aladinhandoklo on 2/3/21.
//

#include <iostream>
#include "find_command.h"

FindCommand::FindCommand(Receiver receiver) : receiver(receiver){}

void FindCommand::execute(std::vector<std::string>& data) {
    if(data.size() == 3){
        receiver.findAction(data[1], data[2]);
    }
    else{
        std::cout << "invalid find command" << std::endl;
    }
}

FindCommand::~FindCommand() {}