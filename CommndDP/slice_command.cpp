//
// Created by aladinhandoklo on 2/2/21.
//

#include <iostream>
#include <sstream>
#include "slice_command.h"

SliceCommand::SliceCommand(Receiver receiver) : receiver(receiver){}

void SliceCommand::execute(std::vector<std::string>& data) {
    int st, en;
    if(data.size() == 5){
        std::stringstream start(data[2]);
        start >> st;
        std::stringstream end(data[3]);
        end >> en;
        receiver.sliceAction(data[1], st, en, data[4]);
    }
    else{
        std::cout << "invalid slice command" << std::endl;
    }
}

SliceCommand::~SliceCommand() {}