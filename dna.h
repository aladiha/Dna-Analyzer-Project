//
// Created by aladinhandoklo on 1/13/21.
//

#ifndef UNTITLED30_DNA_H
#define UNTITLED30_DNA_H

#define BASE_MASK 0x3

#include <string>
#include <tr1/regex>
#include <stdint.h>

/* useful constants */
enum
{
    BASE_A = 0x0, /* binary: 00 */
    BASE_C = 0x1, /* binary: 01 */
    BASE_G = 0x2, /* binary: 10 */
    BASE_T = 0x3, /* binary: 11 */
};

class DnaSequence {

public:
    explicit DnaSequence(const char* sequence);
    explicit DnaSequence(const std::string& sequence);
    char* to_string() const;
    DnaSequence(const DnaSequence&);
    DnaSequence& operator=(const DnaSequence&);
    DnaSequence& operator=(const std::string&);
    DnaSequence& operator=(const char*);
    ~DnaSequence();
    bool operator==(const DnaSequence&)const;
    bool operator!=(const DnaSequence&)const;
    char operator[](size_t index) const;
    size_t getSize() const;

private:
    uint8_t* sequence;
    size_t size;
};

std::ostream& operator<<(std::ostream& os ,const DnaSequence& seq);

#endif //UNTITLED30_DNA_H
