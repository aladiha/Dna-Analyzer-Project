//
// Created by aladinhandoklo on 1/13/21.
//

#include <iostream>
#include "operations.h"


DnaSequence DnaOperations::getSubSequence(size_t start, size_t end, const DnaSequence& seq){
    try {
        if (end > seq.getSize()) {
            throw std::out_of_range("index out of range");
        }
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
        return DnaSequence("");
    }
    size_t i=0, newSize = end-start;
    char* newSeq = new char[newSize+1];
    while(i < newSize){
        newSeq[i++] = seq[start++];
    }
    newSeq[i] = 0;
    return DnaSequence(newSeq);
}


DnaSequence DnaOperations::getPairedDna(const DnaSequence& seq) {
    std::string pairedSeq;
    size_t i;
    try{
        for(i = 0; i < seq.getSize(); ++i) {
            if (seq[i] == 'G')
                pairedSeq.append("C");
            else if (seq[i] == 'C')
                pairedSeq.append("G");
            else if (seq[i] == 'A')
                pairedSeq.append("T");
            else if (seq[i] == 'T')
                pairedSeq.append("A");
            else
                throw std::invalid_argument("unexpected symbol");
        }
    } catch (std::invalid_argument& e) {
        e.what();
        exit(0);
    }
    std::reverse(pairedSeq.begin(),pairedSeq.end());
    return DnaSequence(pairedSeq);
}


int DnaOperations::findSubSequence(const DnaSequence& seq, const std::string& str) {
    if(seq.getSize() < str.length()){
        return -1;
    }
    size_t i,j,k;
    for(i=0; i< seq.getSize()-(str.size()-1);i++){
        j=0;
        k=i;
        while(j<str.size() && str[j] == seq[k]){
            j++;
            k++;
        }
        if(j == str.size()){
            return i;
        }
    }
    return -1;
}

size_t DnaOperations::countSubSequence(const DnaSequence& seq, const std::string& str){
    size_t j,k,i;
    size_t count = 0;
    if(seq.getSize() < str.length()){
        return 0;
    }
    for(i = 0; i < seq.getSize() - (str.size()-1); ++i){
        j=0;
        k=i;
        while(j<str.size() && str[j] == seq[k]){
            j++;
            k++;
        }
        if(j == str.size()){
            count++;
        }
    }
    return count;
}

std::vector<size_t> DnaOperations::findAllSubSequence(const DnaSequence& seq, const std::string& str){
    std::vector<size_t> indexes;
    size_t j,k,i;
    for(i=0; i<seq.getSize()-(str.size()-1);i++){
        j=0;
        k=i;
        while(j<str.size() && str[j] == seq[k]){
            j++;
            k++;
        }
        if(j == str.size()){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<DnaSequence> DnaOperations::findConsensusSequence(const DnaSequence& seq) {
    std::vector<DnaSequence> codonSeqs;
    size_t j,i;
    if (seq.getSize() < 6)
        return codonSeqs;
    for(i=0; i<seq.getSize()-5;i++){
        if(seq[i] == 'A' && seq[i+1] == 'T' && seq[i+2] == 'G'){
            j=i;
            while(i<seq.getSize()-2){
                i+=3;
                if (i >= seq.getSize()){
                    break;
                }
                if((seq[i] == 'T' && seq[i+1] == 'A' && (seq[i+2] == 'G' || seq[i+2] == 'A')) || (seq[i] == 'T' && seq[i+1] == 'G' && seq[i+2] == 'A')) {
                    codonSeqs.push_back(getSubSequence(j,i + 3,seq));
                    break;
                }
            }
        }
    }

    return codonSeqs;
}
