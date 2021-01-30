#include <iostream>
#include "operations.h"
#include "CommndDP/Invoker.h"
#include "CommndDP/new_command.h"
#include "CommndDP/receiver.h"


int main() {

    /*Receiver rec;
    Command* c = new NewCommand(rec);
    Invoker inv(c);
    inv.operation();*/

    while(true) {
        std::string input;
        std::cout << "DnaAnalyzer >> ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        if (results[0] == "quit"){
            break;
        }

        if (results[0] == "new") {

        }
        else if (results[0] == "dup") {

        }
        else if (results[0] == "load") {

        }
        else if(results[0] == "slice"){

        }
        else if(results[0] == "replace"){

        }
    }
    return 0;
}
