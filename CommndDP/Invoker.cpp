//
// Created by aladinhandoklo on 1/27/21.
//

#include "Invoker.h"

Invoker::Invoker(Command* command): command(command) {}

void Invoker::operation() {
    command->execute();
}