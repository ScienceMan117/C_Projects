//**************************************************************************** 
// File name:	DNA.cpp
// Author:		Chadd Williams
// Date:		  3/6/2016
// Class:		  CS 250
// Assignment:04_DNASet
// Purpose:		Demonstrate the DNA class
//****************************************************************************

#include "DNA.h"
#include <iostream>

using namespace std;


//****************************************************************************
// Function:	  main
//
// Description:	Demonstrate the use of class DNA
//
// Parameters:  None
//
// Returned:	  int - EXIT_SUCCESS or EXIT_FAILURE
//***************************************************************************

int main()
{
  DNA cFirstDNA;
  DNA cSecondDNA;
  int length;

  cout << "Please enter up to 20 bases (A,T,C,G): ";
  cin >> cFirstDNA;

  cout << "\nYou entered: ";
  cout << cFirstDNA;

  cout << "\nThe Reverse is: ";
  cout << cFirstDNA.reverse() << endl;


  length = cFirstDNA.getLength();

  do
  {

    cout << "\nPlease enter " << length << " bases (A,T,C,G): ";
    cin >> cSecondDNA;
  } while (cSecondDNA.getLength() != length);

  if (cFirstDNA == cSecondDNA)
  {
    cout << "The DNA strands are the same!\n\n;";
  }
  else
  {
    cout << "The DNA strands are different!\n\n";

    cout << "The P-Stat is: " << cSecondDNA.pstat(cFirstDNA);
    cout << "\n\nThe P-Stat is still: " << cFirstDNA.pstat(cSecondDNA);
    cout << " (just checking)\n\n";
  }


  return EXIT_SUCCESS;
}