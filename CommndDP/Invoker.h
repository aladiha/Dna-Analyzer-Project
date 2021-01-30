//
// Created by aladinhandoklo on 1/27/21.
//

#ifndef UNTITLED30_INVOKER_H
#define UNTITLED30_INVOKER_H

#include "Command.h"

class Invoker{

public:
    explicit Invoker(Command* command);
    void operation();

private:
    Command* command;
};


#endif //UNTITLED30_INVOKER_H
