//**************************************************************************** 
// File name:	DNASet.h
// Author:		Aidan
// Date:		3/11/2016
// Class:		CS 250
// Assignment:  DNA Set 
// Purpose:		Demonstrate classes
//****************************************************************************
#pragma once

#include <ostream>
#include <istream>
#include <set>
#include "DNA.h"
#include <string>

using namespace std;

class DNASet
{

public:
    DNASet ();

    void addDNAStrand (const DNA & DNAObject);
    DNASet set_union (const DNASet & cDNASetObject) const;
    DNASet set_intersection (const DNASet & cDNASetObject) const;
    bool DNASet::contains (const DNA & DNAObject) const;
    friend ostream& operator<<(ostream &out, const DNASet & cDNASetObject);
    friend istream& operator>>(istream &in, DNASet &cDNASetObject);

    static const char ADENINE = 'A';
    static const char THYMINE = 'T';
    static const char CYTOSINE = 'C';
    static const char GUANINE = 'G';

private:
    static const int MAX_STRANDS = 100;
    int mNumberDNAStrands;
    int mdnaLength;
    DNA mDNAArray[MAX_STRANDS];
};

