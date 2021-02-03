//
// Created by aladinhandoklo on 2/3/21.
//

#include <iostream>
#include "count_command.h"


void CountCommand::execute(std::vector<std::string> &data) {
    if(data.size() == 3){
        receiver.countAction(data[1], data[2]);
    }
    else{
        std::cout << "invalid count command" << std::endl;
    }
}

CountCommand::CountCommand(Receiver receiver) : receiver(receiver){}

CountCommand::~CountCommand() {}