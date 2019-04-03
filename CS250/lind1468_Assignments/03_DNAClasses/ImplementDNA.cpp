//*****************************************************************************
// File Name:  ImplementDNA.cpp
// Author:	   Aidan Lindsey
// Date:	   3/9/2016
// Class:	   CS250-02
// Assignment: Assignment 03_DNAClasses
// Purpose:	   Implements the functions created in the Interface.h that will be
//			   called in 03_DNAClasses.cpp
//*****************************************************************************

#include "InterfaceDNA.h"
#include <iostream>
#include <istream>
#include <fstream> 
#include <iomanip>

using namespace std;
/******************************************************************************
Function:     displayHeading

Description:  Displays the heading for the program

Parameters:   none

Returned:     None
******************************************************************************/
void DNA::displayHeading ()
{
    cout << "***********************" << endl;
    cout << "* PACIFIC DNA-O-MATIC *" << endl;
    cout << "***********************" << endl << endl;
}
/******************************************************************************
Function:     properData

Description:  Tests to see if the strand data is valid in the file

Parameters:   istream &inFile - reads the file from DNA.txt to be read and used
              int NumberBases - the number of bases of a DNA strand
              int NumberStrands - the number total number of DNA Strands

Returned:     properData
******************************************************************************/
bool DNA::properData (istream &inFile, int NumberBases, int NumberStrands)
{
    bool properData = true;
    char temporaryArray [MAX][MAX];
    char base = inFile.get();
    int i = 0;
    int baseCounter = 0;

    for (int j = 0; j < NumberStrands; j++)
    {
        while ('\n' != base && i < 100)
        {
            temporaryArray[j][i] = base;
            switch (temporaryArray[j][i])
            {
            case 'A':
                properData = true;
                break;
            case 'T':
                properData = true;
                break;
            case 'G':
                properData = true;
                break;
            case 'C':
                properData = true;
                break;
            default:
                properData = false;
            }
            i++;
            base = inFile.get();
        }
        base = inFile.get();
        j++;
        baseCounter = i;
    }
    if (baseCounter != NumberBases)
    {
        properData = false;
    }

    return properData;

}
/******************************************************************************
Function:     numberBases

Description:  Goes through the file to see how many bases there are in the 
              file DNA.txt

Parameters:   istream &inFile - reads the file from DNA.txt to be read and used

Returned:     NumberBases
******************************************************************************/
int DNA::numberBases (istream &inFile)
{
    char temporaryArray[100];
    char base = inFile.get();    
    int NumberBases = 0;
    int i = 0;

    while ('\n' != base && i < 100)
    {
        temporaryArray[i] = base;
        i++;
        base = inFile.get();
        NumberBases++;
    }
    return NumberBases;
}
/******************************************************************************
Function:     readDNAFile

Description:  Reads the information from the file into mDNAStrandArray[MAX]

Parameters:   istream &inFile - reads the file from DNA.txt to be read and used
              DNA cDNAObject - Object to be used of the class DNA
              int NumberBases - the number of bases of a DNA strand
              int NumberStrands - the number total number of DNA Strands

Returned:     mDNAStrandArray[MAX]
******************************************************************************/
char DNA::readDNAFile(istream &inFile, DNA cDNAObject, int NumberBases, int NumberStrands)
{
    char base = inFile.get();
    int i = 0;
    int j = 0;

    while (j < 2)
    {
        while (('\n' != base && EOF != base) && i < MAX)
        {
            mDNAStrandArray[i] = base;
            i++;
            base = inFile.get();
        }
        base = inFile.get();
        j++;
    }

    mDNAStrandArray[i] = '\0';
    return mDNAStrandArray[i];
}
/******************************************************************************
Function:     numberStrands

Description:  Goes through the array and counts how many DNA strands there are 
              in the file

Parameters:   istream &inFile - reads the file from DNA.txt to be read and used

Returned:     NumberStrands
******************************************************************************/
int DNA::numberStrands(istream &inFile)
{
    string line;
    int NumberStrands = 0;
    while (getline(inFile, line))
    {
        ++NumberStrands;
    }
    return NumberStrands;
}
/******************************************************************************
Function:     readUserDNAStrand

Description:  Allows the user to input a DNA Strand into a char array 

Parameters:   ostream &out - allows the user to output any data at any time
              istream &in - allows the user to input any data at any time
              int NumberBases - the number of bases of a DNA strand

Returned:     mUserStrandArray[i]
******************************************************************************/
char DNA::readUserDNAStrand(ostream &out, istream &in, int NumberBases)
{
    int i = 0;
    cout << "DNA (Length=" << NumberBases << "): ";
    while (i < NumberBases)
    {
        cin >> mUserStrandArray[i];
        i++;
    }
    cout << endl;
    return mUserStrandArray[i];
}
/******************************************************************************
Function:     printOriginal

Description:  Prints the 2 DNA strandds in mDNAStrandArray[100] and also prints 
              the DNA strand that was created by the user

Parameters:   ostream &out - allows the user to output any data at any time
              DNA cDNAObject - Object to be used of the class DNA
              char mDNAStrandArray[MAX] - the first 2 DNA strands from the file 
              char mUSerStrandArray[MAX] - the DNA strand inputted by the user
              int NumberBases - the number of bases of a DNA strand

Returned:     None
******************************************************************************/
void DNA::printOriginal(ostream &out, DNA cDNAObject, char mDNAStrandArray[MAX], char mUserStrandArray[MAX], int NumberBases)
{
    int totalLength = NumberBases * 2;
    int i = 0;
    int j = 0;

    out << "Original" << endl << endl;
    while (NULL != cDNAObject.mDNAStrandArray[i])
    {
        if (i < NumberBases)
        {
            if (i == 0)
            {
                cout << "SO: ";
            }
            cout << cDNAObject.mDNAStrandArray[i];
        }
        if (i >= NumberBases && i < totalLength)
        {
            if (i == NumberBases)
            {
                cout << endl << "S1: ";
            }
            cout << cDNAObject.mDNAStrandArray[i];
        }
        i++;
    }
    cout << endl << "S2: ";
    while (j < NumberBases)
    {
         cout << cDNAObject.mUserStrandArray[j];
        j++;
    }
    cout << endl << endl;
}
/******************************************************************************
Function:     createReverse

Description:  Creates the Reverse DNA strands of mDNAStrandArray[MAX] and
              mUserStrandArray[MAX], stores them in new arrays and then prints
              them to the screen

Parameters:   ostream &out - allows the user to output any data at any time
              DNA cDNAObject - Object to be used of the class DNA
              char mDNAStrandArray[MAX] - the first 2 DNA strands from the file
              char ReverseStrandArray[MAX] - holds the reverse DNA strands of
                                             mDNAStrandArray[MAX]
              char ReverseUserArray[MAX] - holds the reverse DNA strand of
                                           mUserStrandArray[MAX]
              char mUSerStrandArray[MAX] - the DNA strand inputted by the user
              int NumberBases - the number of bases of a DNA strand


Returned:     mUserStrandArray[i]
******************************************************************************/
void DNA::createReverse(ostream &out, DNA cDNAObject, char mDNAStrandArray[MAX], char ReverseStrandArray[MAX], char ReverseUserArray[MAX],
                        char mUserStrandArray[MAX], int NumberBases)
{
    cout << "Reverse" << endl << endl;
    int completeLength = NumberBases * 2;
    for (int i = 0; i < completeLength; i++)
    {
        ReverseStrandArray[completeLength - i - 1] = cDNAObject.mDNAStrandArray[i];
    }
    for (int i = 0; i < NumberBases; i++)
    {
        ReverseUserArray[NumberBases - i - 1] = cDNAObject.mUserStrandArray[i];
    }
    cout << "SO: ";
    for (int i = NumberBases; i < completeLength; i++)
    {
        cout << ReverseStrandArray[i];
    }
    cout << endl;
    cout << "S1: ";
    for (int i = 0; i < NumberBases; i++)
    {
        cout << ReverseStrandArray[i];
    }
    cout << endl;
    cout << "S2: ";
    for (int i = 0; i < NumberBases; i++)
    {
        cout << ReverseUserArray[i];
    }
    cout << endl << endl;
}
/******************************************************************************
Function:     secondReverse

Description:  Creates the second Reverse DNA strands of ReverseStrand[MAX] and
              ReverseUserArray[MAX], stores them in new arrays and then prints
              them to the screen

Parameters:   ostream &out - allows the user to output any data at any time
              char SecondReverseStrandArray[MAX] - holds the second reverse 
                                                   DNA strands from
                                                   ReverseStrandArray[MAX]
              char SecondReverseUserArray[MAX] - holds the second reverse 
                                                   DNA strands from
                                                   ReverseUserArray[MAX]
              char ReverseStrandArray[MAX] - holds the reverse DNA strands of
                                             mDNAStrandArray[MAX]
              char ReverseUserArray[MAX] - holds the reverse DNA strand of
                                           mUserStrandArray[MAX]
              int NumberBases - the number of bases of a DNA strand

Returned:     None
******************************************************************************/
void DNA::secondReverse(ostream &out, char SecondReverseStrandArray[MAX], char ReverseStrandArray[MAX], char ReverseUserArray[MAX],
                        char SecondReverseUserArray[MAX], int NumberBases)
{
    cout << "Reverse Reverse (should match original)" << endl << endl;
    int completeLength = NumberBases * 2;

    for (int i = 0; i < completeLength; i++)
    {
        SecondReverseStrandArray[completeLength - i - 1] = ReverseStrandArray[i];
    }
    for (int i = 0; i < NumberBases; i++)
    {
        SecondReverseUserArray[NumberBases - i - 1] = ReverseUserArray[i];
    }
    cout << "SO: ";
    for (int i = 0; i < NumberBases; i++)
    {
        cout << SecondReverseStrandArray[i];
    }
    cout << endl;
    cout << "S1: ";
    for (int i = NumberBases; i < completeLength; i++)
    {
        cout << SecondReverseStrandArray[i];
    }
    cout << endl;
    cout << "S2: ";
    for (int i = 0; i < NumberBases; i++)
    {
        cout << SecondReverseUserArray[i];
    }
    cout << endl << endl;
}
/******************************************************************************
Function:     secondReverse

Description:  Creates the Reverse complimentary DNA strands of ReverseStrand[MAX] 
              and ReverseUserArray[MAX], stores them in new arrays and then prints
              them to the screen

Parameters:   ostream &out - allows the user to output any data at any time
              char ReverseComplimentaryStrandArray[MAX] - holds the reverse 
              compliment DNA strands from reverseStrandArray[MAX]
              char SecondReverseUserArray[MAX] - holds the reverse
              Complimentary DNA strands from reverseUserArray[MAX]
              char ReverseStrandArray[MAX] - holds the reverse DNA strands of
                                             mDNAStrandArray[MAX]
              char ReverseUserArray[MAX] - holds the reverse DNA strand of
                                           mUserStrandArray[MAX]
              int NumberBases - the number of bases of a DNA strand

Returned:     None
******************************************************************************/
void DNA::createReverseCompliment(ostream &out, DNA cDNAObject, char ReverseStrandArray[100], char ReverseUserArray[100], int NumberBases,
    char ReverseComplimentStrandArray[100], char ReverseComplimentUserArray[100])
{
    cout << "Reverse Complement" << endl << endl;
    int completeLength = NumberBases * 2;
    for (int i = 0; i < completeLength; i++)
    {
        switch (ReverseStrandArray[i])
        {
        case 'A':
            ReverseComplimentStrandArray[i] = 'T';
            break;
        case 'T':
            ReverseComplimentStrandArray[i] = 'A';
            break;
        case 'G':
            ReverseComplimentStrandArray[i] = 'C';
            break;
        case 'C':
            ReverseComplimentStrandArray[i] = 'G';
            break;
        }
    }
    for (int i = 0; i < NumberBases; i++)
    {
        switch (ReverseUserArray[i])
        {
        case 'A':
            ReverseComplimentUserArray[i] = 'T';
            break;
        case 'T':
            ReverseComplimentUserArray[i] = 'A';
            break;
        case 'G':
            ReverseComplimentUserArray[i] = 'C';
            break;
        case 'C':
            ReverseComplimentUserArray[i] = 'G';
            break;
        }
    }
    cout << "SO: ";
    for (int i = NumberBases; i < completeLength; i++)
    {
        cout << ReverseComplimentStrandArray[i];
    }
    cout << endl;
    cout << "S1: ";
    for (int i = 0; i < NumberBases; i++)
    {
        cout << ReverseComplimentStrandArray[i];
    }
    cout << endl;
    cout << "S2: ";
    for (int i = 0; i < NumberBases; i++)
    {
        cout << ReverseComplimentUserArray[i];
    }
    cout << endl << endl;
}
/******************************************************************************
Function:     pStat

Description:  Calculates the pStat from all the DNA strands in the file with
              the DNA Strand inputted by the user and prints them to the screen

Parameters:   ostream &out - allows the user to output any data at any time
              istream &inFile - reads the file from DNA.txt to be read and used
              DNA cDNAObject - Object to be used of the class DNA
              char mUSerStrandArray[MAX] - the DNA strand inputted by the user
              int NumberBases - the number of bases of a DNA strand
              int NumberStrands - the number total number of DNA Strands

Returned:     None
******************************************************************************/
void DNA::pStat(ostream &out, istream &inFile, DNA cDNAObject, char mUserStrandArray[100], int NumberBases, int NumberStrands)
{
    char temporaryArray[100][100];
    char base = inFile.get();    
    double pStat = 0.00;
    double recorder = 0.00;
    int strand = 0;

    for (int i = 0; i < NumberStrands; i++)
    {
        for (int j = 0; j < NumberBases; j++)
        {
            temporaryArray[i][j] = base;
            base = inFile.get();
        }
        base = inFile.get();
    }

    for (int i = 0; i < NumberStrands; i++)
    {
        double counter = 0.00;
        for (int j = 0; j < NumberBases; j++)
        {            
            if (cDNAObject.mUserStrandArray[j] != temporaryArray[i][j])
            {
                counter++;
            }
        }
        if (counter == recorder || counter < recorder)
        {
            recorder = counter;
            strand = i;
        }
        if (counter > recorder)
        {
           recorder = counter;
        }        
     }

    pStat = recorder / NumberBases;

    out << "Most Similar" << endl << endl;
    out << "Keyboard: ";
    
    for (int i = 0; i < NumberBases; i++)
    {
        out << cDNAObject.mUserStrandArray[i];
    }
    
    cout << endl;
    out << "File    : ";

    for (int i = 0; i < NumberBases; i++)
    {
        out << temporaryArray[strand][i];
    }

    out << endl << "P-Stat  : " << fixed << setprecision(2) << pStat << endl << endl;

    
}