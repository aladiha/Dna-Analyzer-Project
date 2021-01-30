//
// Created by aladinhandoklo on 1/13/21.
//

#ifndef UNTITLED30_OPERATIONS_H
#define UNTITLED30_OPERATIONS_H

#include "dna.h"

class DnaOperations{
public:
    static DnaSequence getSubSequence(size_t start, size_t end, const DnaSequence& seq);
    static DnaSequence getPairedDna(const DnaSequence& seq);
    static int findSubSequence(const DnaSequence& seq, const std::string& str);
    static size_t countSubSequence(const DnaSequence& seq, const std::string& str);
    static std::vector<size_t> findAllSubSequence(const DnaSequence& seq, const std::string& str);
    static std::vector<DnaSequence> findConsensusSequence(const DnaSequence& seq);
};

#endif //UNTITLED30_OPERATIONS_H
