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

    //phase 1
    DnaSequence dnaSequence("ACGTA");
    std::string a = "AACTT";
    DnaSequence seq(a);
    std::cout << dnaSequence << std::endl;
    std::cout << seq << std::endl;
    DnaSequence seq2("AA");
    seq = seq2;
    std::cout << seq << std::endl;
    seq = "ACCCCC";
    std::cout << seq << std::endl;
    seq2 = std::string("CACGTACGTAAACCTTACGT");
    std::cout << seq2 << std::endl;
    std::cout << (seq == seq2) << std::endl;

    // phase 2
    DnaSequence mySeq = DnaOperations::getSubSequence(0,5, dnaSequence);
    std::cout << mySeq << std::endl;
    mySeq = DnaOperations::getPairedDna(mySeq);
    std::cout << mySeq << std::endl;
    std::cout << DnaOperations::findSubSequence(mySeq, "CGT") << std::endl; // TACGT
    std::cout << DnaOperations::countSubSequence(mySeq, "T") << std::endl; // TACGT
    std::vector<size_t> v = DnaOperations::findAllSubSequence(seq2, "ACGT");
    for (size_t i = 0 ; i < v.size() ; i++){
        std::cout << v[i] << " ";
    }
    DnaSequence s("ATGTTTCCCTACTAAATGGGGGGGGGGTGA");
    std::vector<DnaSequence> v2 = DnaOperations::findConsensusSequence(s);
    for (size_t i = 0 ; i < v2.size() ; i++){
        std::cout << v2[i] << " ";
    }
    return 0;
}
