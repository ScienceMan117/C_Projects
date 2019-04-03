//**************************************************************************** 
// File name:	DNA.h
// Author:		Chadd Williams
// Date:		  2/24/2016
// Class:		  CS 250
// Assignment:04_DNASet
// Purpose:		DNA class for public use
//****************************************************************************

#include <iostream>

using namespace std;

class DNA
{

public:

  static const int MAX_BASES = 20;

  DNA();

  DNA reverse() const;
  DNA complement() const;


  double pstat(const DNA &cCtherDNA) const;

  int getLength() const;


  bool operator==(const DNA &cDNA) const;

  friend ostream& operator<<(ostream &out, const DNA &cDNA);
  friend istream& operator>>(istream &in, DNA &cDNA);

  static const char ADENINE = 'A';
  static const char THYMINE = 'T';
  static const char CYTOSINE = 'C';
  static const char GUANINE = 'G';

private:
  char mszDNA[MAX_BASES + 1];
  bool isValidBase(char ch) const;

};