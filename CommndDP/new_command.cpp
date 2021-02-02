//
// Created by aladinhandoklo on 1/27/21.
//

#include <iostream>
#include "new_command.h"
#include "../dna.h"

NewCommand::NewCommand(Receiver receiver) : receiver(receiver){}

void NewCommand::execute(std::vector<std::string>& data) {
    if(data.size() == 3){
        try{
            DnaSequence dna(data[1]);
        }
        catch(std::invalid_argument& e){
            std::cout << e.what() << std::endl;
            return;
        }
        receiver.newAction(data[1], data[2]);
        std::cout << data[2] + " sequence was added." << std::endl;
    }
    else{
        std::cout << "invalid new command" << std::endl;
    }
}

NewCommand::~NewCommand() {}


