//
// Created by aladinhandoklo on 2/3/21.
//

#include "list_command.h"

ListCommand::ListCommand(Receiver receiver): receiver(receiver) {}

void ListCommand::execute(std::vector<std::string> &data) {
    receiver.listAction();
}

ListCommand::~ListCommand() {

}
