//
// Created by aladinhandoklo on 1/27/21.
//

#include "new_command.h"

NewCommand::NewCommand(Receiver receiver) : receiver(receiver){}

void NewCommand::execute() {
    receiver.action();
}
