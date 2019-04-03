//*****************************************************************************
// File Name:  InterfaceDNA.h
// Author:	   Aidan Lindsey
// Date:	   3/9/2016
// Class:	   CS250-02
// Assignment: Assignment 03_DNAClasses
// Purpose:	   Create the interface for the DNA classes assignment, creating a 
//             classes and then writing functions to be implemented
//*****************************************************************************

// Allow the file to be only read once before being closed
#pragma once

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
using namespace std;
 
const int MAX = 100;
class DNA
{
public: 
    void displayHeading ();
    bool properData (istream &inFile, int NumberBases, int NumberStrands);
    char readDNAFile (istream &inFile, DNA cDNAObject, int NumberBases, int NumberStrands);
    int numberStrands (istream &inFile);
    int numberBases (istream &inFile);
    char readUserDNAStrand (ostream &out, istream &in, int NumberBases);
    void printOriginal(ostream &out, DNA cDNAObject, char mDNAStrandArray[MAX], char mUserStrandArray[MAX],
                        int NumberBases);
    void createReverse(ostream &out, DNA cDNAObject, char mDNAStrandArray[MAX], char ReverseStrandArray[MAX],
                        char ReverseUserArray[MAX], char mUserStrandArray[MAX], int NumberBases);
    void secondReverse(ostream &out, char SecondReverseStrandArray[MAX], char ReverseStrandArray[MAX],
                        char ReverseUserArray[MAX], char SecondReverseUserArray[MAX], int NumberBases);
    void createReverseCompliment(ostream &out, DNA cDNAObject, char ReverseStrandArray[MAX],
                                 char ReverseUserArray[MAX], int NumberBases, char ReverseComplimentStrandArray[100],
                                 char ReverseComplimentUserArray[MAX]);
    void pStat(ostream &out, istream &inFile, DNA cDNAObject, char mUserStrandArray[MAX], int NumberBases, 
               int NumberStrands);
private: 
    char mDNAStrandArray[MAX];
    char mUserStrandArray[MAX];
};