//
// Created by aladinhandoklo on 1/13/21.
//

#include "dna.h"
#include <cstring>
#include <iostream>

DnaSequence::DnaSequence(const char* mySequence){
    size = strlen(mySequence);

    size_t dna_bytes = (size / 4) + (size % 4 != 0); // 8 letters /4  =  2 + 0
    sequence = new uint8_t[dna_bytes];  // 2
    std::memset(sequence, 0, dna_bytes);

    for (size_t i = 0; i < size; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (mySequence[i])
        {
            case 'A':
                sequence[i / 4] |= BASE_A << shift; // 00
                break;
            case 'C':
                sequence[i / 4] |= BASE_C << shift; // 01
                break;
            case 'G':
                sequence[i / 4] |= BASE_G << shift; // 10
                break;
            case 'T':
                sequence[i / 4] |= BASE_T << shift; // 11
                break;
            default:
                throw std::invalid_argument("invalid DNA base");
        }
    }
}

char* DnaSequence::to_string() const{
    char* dna_str = new char[size + 1];

    /* for each base of the DNA sequence */
    for (size_t i = 0; i < size; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);
        uint8_t mask = BASE_MASK << shift;

        /* get the i-th DNA base */
        uint8_t base = (sequence[i / 4] & mask) >> shift;

        switch (base)
        {
            case BASE_A:
                dna_str[i] = 'A';
                break;
            case BASE_C:
                dna_str[i] = 'C';
                break;
            case BASE_G:
                dna_str[i] = 'G';
                break;
            case BASE_T:
                dna_str[i] = 'T';
                break;
            default:
                throw std::runtime_error("invalid DNA base");
        }
    }

    dna_str[size] = '\0';
    return dna_str;
}



DnaSequence::DnaSequence(const std::string& mySequence) {
    size = mySequence.length();

    size_t dna_bytes = (size / 4) + (size % 4 != 0);
    sequence = new uint8_t[dna_bytes];

    std::memset(sequence, 0, dna_bytes);

    for (size_t i = 0; i < size; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (mySequence[i])
        {
            case 'A':
                sequence[i / 4] |= BASE_A << shift;
                break;
            case 'C':
                sequence[i / 4] |= BASE_C << shift;
                break;
            case 'G':
                sequence[i / 4] |= BASE_G << shift;
                break;
            case 'T':
                sequence[i / 4] |= BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA base");
        }
    }
}


DnaSequence::DnaSequence(const DnaSequence& otherSequence){
    size = otherSequence.size;
    size_t dna_bytes = (size / 4) + (size % 4 != 0);
    sequence = new uint8_t[dna_bytes];
    memcpy(sequence, otherSequence.sequence, dna_bytes);
}

DnaSequence& DnaSequence::operator=(const DnaSequence& otherSequence) {
    if(this == &otherSequence)
        return *this;
    delete[] sequence;
    size = otherSequence.size;
    size_t dna_bytes = (size / 4) + (size % 4 != 0);
    sequence = new uint8_t[dna_bytes];
    memcpy(sequence,otherSequence.sequence, dna_bytes);
    return *this;
}


DnaSequence& DnaSequence::operator=(const std::string& mySequence) {
    delete[] sequence;
    size = mySequence.length();
    size_t dna_bytes = (size / 4) + (size % 4 != 0);
    sequence = new uint8_t[dna_bytes];
    std::memset(sequence, 0, dna_bytes);

    for (size_t i = 0; i < size; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (mySequence[i])
        {
            case 'A':
                sequence[i / 4] |= BASE_A << shift;
                break;
            case 'C':
                sequence[i / 4] |= BASE_C << shift;
                break;
            case 'G':
                sequence[i / 4] |= BASE_G << shift;
                break;
            case 'T':
                sequence[i / 4] |= BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA base");
        }
    }
    return *this;
}

DnaSequence& DnaSequence::operator=(const char* mySequence) {
    delete[] sequence;
    size = strlen(mySequence);
    size_t dna_bytes = (size / 4) + (size % 4 != 0);
    sequence = new uint8_t[dna_bytes];
    std::memset(sequence, 0, dna_bytes);

    for (size_t i = 0; i < size; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (mySequence[i])
        {
            case 'A':
                sequence[i / 4] |= BASE_A << shift;
                break;
            case 'C':
                sequence[i / 4] |= BASE_C << shift;
                break;
            case 'G':
                sequence[i / 4] |= BASE_G << shift;
                break;
            case 'T':
                sequence[i / 4] |= BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA base");
        }
    }
    return *this;
}


DnaSequence::~DnaSequence(){
    delete[] sequence;
}


bool DnaSequence::operator==(const DnaSequence& otherSequence) const{
    if(size == otherSequence.size){
        for(size_t i=0; i < size; i++){
            if((*this)[i] != otherSequence[i])
                return false;
        }
        return true;
    }
    return false;
}

bool DnaSequence::operator!=(const DnaSequence& otherSequence)const {
    return !(*this == otherSequence);
}

char DnaSequence::operator[](size_t i) const{
    try {
        if (i >= size) {
            throw std::out_of_range("index out of range");
        }
        uint8_t shift = 6 - 2 * (i % 4);
        uint8_t mask = BASE_MASK << shift;

        /* get the i-th DNA base */
        uint8_t base = (sequence[i / 4] & mask) >> shift;

        switch (base) {
            case BASE_A:
                return 'A';
            case BASE_C:
                return 'C';
            case BASE_G:
                return 'G';
            case BASE_T:
                return 'T';
            default:
                throw std::out_of_range("index out of range");
        }
    }
    catch (std::out_of_range& e) {
        std::cout << e.what();
        exit(0);
    }
}

size_t DnaSequence::getSize() const{
    return size;
}


std::ostream& operator<<(std::ostream& os ,const DnaSequence& seq){
    os << seq.to_string();
    return os;
}