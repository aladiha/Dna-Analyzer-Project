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
        std::cout << "could not find_command a sequence with the name " << name << std::endl;
    }
}

void Receiver::duplicateAction(const std::string& name, const std::string& secondName) {
    std::string sequence = FileManager::read_from_file(name);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << name << std::endl;
    }
    else{
        FileManager::write_to_file(sequence, secondName);
        std::cout << "sequence duplicated successfully." << std::endl;
    }
}

void Receiver::sliceAction(const std::string &name, int startIndex, int endIndex, const std::string &secondName) {
    std::string sequence = FileManager::read_from_file(name);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << name << std::endl;
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

void Receiver::replaceAction(const std::string &name, int index, const std::string &newLetter) {
    std::string sequence = FileManager::read_from_file(name);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << name << std::endl;
    }
    else{
        if(index >= 0  and index < sequence.size()){
            sequence[index] = newLetter[0];
            FileManager::delete_file(name);
            FileManager::write_to_file(sequence, name);
            std::cout << "updated sequence " << name << " to " << sequence << std::endl;
        }
        else{
            std::cout << "index out of range!" << std::endl;
        }
    }
}

void Receiver::concatAction(const std::string& firstSeq,const std::string& secSeq,const std::string& newName) {
    std::string sequence = FileManager::read_from_file(firstSeq);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << firstSeq << std::endl;
        return;
    }
    std::string sequence2 = FileManager::read_from_file(secSeq);
    if(sequence2.empty()){
        std::cout << "could not find_command a sequence with the name " << secSeq << std::endl;
        return;
    }
    std::string seq = sequence + sequence2;
    FileManager::write_to_file(seq, newName);
    std::cout << "added the sequence " << newName << std::endl;
}

void Receiver::pairAction(const std::string &seqName,const std::string &newName) {
    std::string sequence = FileManager::read_from_file(seqName);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << seqName << std::endl;
        return;
    }
    DnaSequence dna(sequence);
    DnaSequence dnaSeq = DnaOperations::getPairedDna(dna);
    std::string paired = dnaSeq.to_string();
    FileManager::write_to_file(paired, newName);
    std::cout << "added the sequence " << newName << std::endl;
}

void Receiver::findAction(const std::string &seqName,const std::string &subSeq) {
    std::string sequence = FileManager::read_from_file(seqName);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << seqName << std::endl;
        return;
    }
    DnaSequence dna(sequence);
    int index = DnaOperations::findSubSequence(dna, subSeq);
    std::cout << "sub sequence is located at index " << index << std::endl;
}

void Receiver::countAction(const std::string &seqName,const std::string &subSeq) {
    std::string sequence = FileManager::read_from_file(seqName);
    if(sequence.empty()){
        std::cout << "could not find_command a sequence with the name " << seqName << std::endl;
        return;
    }
    DnaSequence dna(sequence);
    int counter = DnaOperations::countSubSequence(dna, subSeq);
    std::cout << "number of sub sequences in the sequence is " << counter << std::endl;
}

void Receiver::HelpAction() {
    std::cout << "\n                 * Menu *\n\n";

    std::cout << "* save a new sequence: format - new <sequence> <sequence name>\n\n";
    std::cout << "* load an existing sequence: format - load <sequence name>\n\n";
    std::cout << "* duplicate an existing sequence: format - dup <sequence name> <new sequence name>\n\n";
    std::cout << "* slice an existing sequence: format - slice <sequence name> <starting index> <ending index> <sequence new name>\n\n";
    std::cout << "* replace a character in sequence: format - replace <sequence name> <index> <new character>\n\n";
    std::cout << "* create pair for a sequence: format - pair <sequence name> <new sequence name>\n\n";
    std::cout << "* find a sub sequence in a sequence: format - find <sequence name> <sub sequence>\n\n";
    std::cout << "* count appearances of sub sequence in sequence: format - count <sequence name> <sub sequence>\n\n";
    std::cout << "* list all sequences in system: format - list\n\n";

}

void Receiver::listAction() {
    std::vector<std::string*> files = FileManager::get_files();
    int i = 0;
    while(i < files.size()){
        if (i > 0) {
            FileManager::read_with_suffix(files[i]);
        }
        i++;
    }
}



