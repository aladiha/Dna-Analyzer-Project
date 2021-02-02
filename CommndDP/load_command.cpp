//
// Created by aladinhandoklo on 2/2/21.
//

#include <iostream>
#include "load_command.h"

LoadCommand::LoadCommand(Receiver receiver): receiver(receiver) {}

void LoadCommand::execute(std::vector<std::string> &data) {
    if(data.size() == 2){
        receiver.loadAction(data[1]);
    }
    else{
        std::cout << "invalid load command" << std::endl;
    }
}

LoadCommand::~LoadCommand() {}
