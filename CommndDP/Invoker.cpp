//
// Created by aladinhandoklo on 1/27/21.
//

#include <string>
#include "Invoker.h"

Invoker::Invoker(Command* command): command(command) {}

void Invoker::operation(std::vector<std::string>& data) {
    command->execute(data);
}