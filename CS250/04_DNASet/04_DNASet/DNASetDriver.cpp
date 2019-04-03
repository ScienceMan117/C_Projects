//*****************************************************************************
// File Name:  04_DNASetDriver.cpp
// Author:	   Aidan Lindsey
// Date:	   3/18/2016
// Class:	   CS250-02
// Assignment: Assignment 04_DNASet
// Purpose:	   Use multiple projects to move data from a file around and input
//             to the screen
//*****************************************************************************
#include <iostream>
#include "DNASet.h"
#include <set>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    DNASet cDNASetObject1;
    DNASet cDNASetObject2;

    DNA DNAObject;

    ifstream inFilePool1;
    ifstream inFilePool2;

    inFilePool1.open ("Pool1.txt");

    if (!inFilePool1)
    {
        cout << "Error: Could not open DNA pool 1 file";
        return EXIT_FAILURE;
    }

    inFilePool2.open ("Pool2.txt");

    if (!inFilePool2)
    {
        cout << "Error: Could not open DNA pool 2 file";
        return EXIT_FAILURE;
    }
    cout << "*********************" << endl;
    cout << "* DNA POOL ANALYZER *" << endl;
    cout << "*********************" << endl;
    
    cout << "Pool 1" << endl << "------" << endl;
    cout << endl << endl;

    cout << "Pool 2" << endl << "------" << endl;
    cout << endl << endl;

    cout << "In both Pools" << endl << "-------------";
    cout << endl << endl;

    cout << "In at least one Pool" << endl << "--------------------";
    cout << endl << endl;

    cout << "Longest Strand in each Pool" << endl;
    cout << "---------------------------" << endl;
    cout << endl << endl;

    cout << "Most Similar:" << endl << "-------------";
    cout << endl << endl;


    inFilePool1.close ();
    inFilePool2.close ();

    return EXIT_SUCCESS;
}

