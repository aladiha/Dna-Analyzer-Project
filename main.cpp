#include <iostream>
#include "operations.h"
#include "CommndDP/Invoker.h"
#include "CommndDP/new_command.h"
#include "CommndDP/receiver.h"
#include "CommndDP/load_command.h"
#include "CommndDP/duplicate_command.h"
#include "CommndDP/slice_command.h"


int main() {


    while(true) {
        std::string input;
        std::cout << "DnaAnalyzer >> ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        Receiver rec;

        if (results[0] == "quit"){
            break;
        }

        if (results[0] == "new") {
            Command* c = new NewCommand(rec);
            Invoker inv(c);
            inv.operation(results);
            delete c;
        }
        else if (results[0] == "dup") {

            Command* c = new DuplicateCommand(rec);
            Invoker inv(c);
            inv.operation(results);
            delete c;
        }
        else if (results[0] == "load") {
            Command* c = new LoadCommand(rec);
            Invoker inv(c);
            inv.operation(results);
            delete c;
        }
        else if(results[0] == "slice"){
            Command* c = new SliceCommand(rec);
            Invoker inv(c);
            inv.operation(results);
            delete c;
        }
        else if(results[0] == "replace"){
            Command* c = new ReplaceCommand(rec);
            Invoker inv(c);
            inv.operation(results);
            delete c;
        }
    }
    return 0;
}
