//
// Created by aladinhandoklo on 2/3/21.
//

#include "help_command.h"


HelpCommand::HelpCommand(Receiver receiver) : receiver(receiver){}

void HelpCommand::execute(std::vector<std::string>& data) {
    receiver.HelpAction();
}

HelpCommand::~HelpCommand() {}