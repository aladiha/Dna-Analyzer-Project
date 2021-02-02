//
// Created by aladinhandoklo on 1/27/21.
//

#include <iostream>
#include "receiver.h"
#include "../dna.h"
#include "../operations.h"


void Receiver::newAction(const std::string& sequence, const std::string& name) {
    FileManager::write_to_file(sequence, name);
}

void Receiver::loadAction(const std::string &name) {
    if(FileManager::read_from_file(name).empty()){
        std::cout << "could not find a sequence with the name " << name << std::endl;
    }
}

void Receiver::duplicateAction(const std::string& name, const std::string& secondName) {
    std::string sequence = FileManager::read_from_file(name);
    if(sequence.empty()){
        std::cout << "could not find a sequence with the name " << name << std::endl;
    }
    else{
        FileManager::write_to_file(sequence, secondName);
        std::cout << "sequence duplicated successfully." << std::endl;
    }
}

void Receiver::sliceAction(const std::string &name, int startIndex, int endIndex, const std::string &secondName) {
    std::string sequence = FileManager::read_from_file(name);
    if(sequence.empty()){
        std::cout << "could not find a sequence with the name " << name << std::endl;
    }
    else{
        try{
            DnaSequence dna(sequence);
            DnaSequence subSeq = DnaOperations::getSubSequence(startIndex,endIndex,dna);
            std::string newSeq(subSeq.to_string());
            if(!newSeq.empty()) {
                FileManager::write_to_file(newSeq, secondName);
                std::cout << "sub sequence added successfully." << std::endl;
            }
        }
        catch(std::invalid_argument& e){
            std::cout << e.what() << std::endl;
            return;
        }
    }

}



