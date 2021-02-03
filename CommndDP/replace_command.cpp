//
// Created by aladinhandoklo on 2/2/21.
//

#include <iostream>
#include <sstream>
#include "replace_command.h"

ReplaceCommand::ReplaceCommand(Receiver receiver): receiver(receiver) {}

void ReplaceCommand::execute(std::vector<std::string>& data) {
    int index;
    if(data.size() == 4){
        std::stringstream ind(data[2]);
        ind >> index;
        if(data[3] == "A" || data[3] == "G" || data[3] == "C" || data[3] == "G"){
            receiver.replaceAction(data[1], index, data[3]);
        }
        else{
            std::cout << "invalid dna character." << std::endl;
        }
    }
    else{
        std::cout << "invalid replace command." << std::endl;
    }
}

ReplaceCommand::~ReplaceCommand() {}