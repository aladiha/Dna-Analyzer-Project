//
// Created by aladinhandoklo on 1/27/21.
//

#ifndef UNTITLED30_COMMAND_H
#define UNTITLED30_COMMAND_H


class Command {
public:
    virtual void execute(std::vector<std::string>& data) = 0;
    virtual ~Command(){};
};




#endif //UNTITLED30_COMMAND_H
