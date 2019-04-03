//**************************************************************************** 
// File name:	DNA.cpp
// Author:		Chadd Williams
// Date:		  2/24/2016
// Class:		  CS 250
// Assignment:04_DNASet
// Purpose:		Implement the DNA class
//****************************************************************************

#include "DNA.h"

//****************************************************************************
// Constructor:	DNA
//
// Description:	Initialize the strand to empty
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
DNA::DNA()
{
  mszDNA[0] = '\0';
}

//****************************************************************************
// Method:	    reverse
//
// Description:	Produce the reverse of the current DNA
//
// Parameters:  none
//
// Returned:	  DNA - a new DNA object that is the reverse of the 
//              current object
//***************************************************************************

DNA DNA::reverse() const
{
  DNA newDNA;

  int length = getLength();

  for (int i = 0; i < length && i< MAX_BASES; i++)
  {
    newDNA.mszDNA[length - i - 1] = mszDNA[i];
  }
  newDNA.mszDNA[length] = '\0';

  return newDNA;
}

//****************************************************************************
// Method:	    complement
//
// Description:	Produce the complement of the current DNA
//
// Parameters:  none
//
// Returned:	  DNA - a new DNA object that is the complement of the 
//              current object
//***************************************************************************

DNA DNA::complement() const
{
  int length = getLength();
  DNA newDNA;

  for (int i = 0; i < length && i< MAX_BASES; i++)
  {
    switch (mszDNA[i])
    {
    case ADENINE:
      newDNA.mszDNA[i] = THYMINE;
      break;
    case THYMINE:
      newDNA.mszDNA[i] = ADENINE;
      break;
    case GUANINE:
      newDNA.mszDNA[i] = CYTOSINE;
      break;
    case CYTOSINE:
      newDNA.mszDNA[i] = GUANINE;
      break;
    }
  }
  newDNA.mszDNA[length] = '\0';

  return newDNA;
}


//****************************************************************************
// Function:	    operator>> (friend of the class)
//
// Description:	Read a DNA string from a stream.  The DNA strand in the stream
//              must be terminated by whitespace.  The DNA strand in the mszDNA
//              member variable is NULL terminated.
//
// Parameters:  in - the stream to read from
//              cDNA - the DNA to fille
//
// Returned:	  istream& - the stream read from
//***************************************************************************

istream& operator>>(istream &in, DNA &cDNA)
{
  char charData;
  int currentDNACharacter = 0;
  bool bDone = false;

  // make sure the last position in the 
  // array contains \0 in case we kick out 
  // of the loop because of reading too many 
  // characters
  cDNA.mszDNA[cDNA.MAX_BASES] = '\0';
  
  while (!bDone && !in.eof() && currentDNACharacter < cDNA.MAX_BASES)
  {
    if (!in.get(charData) || isspace(charData))
    {

      // found a whitespace so we reached the end of 
      // a DNA string
      bDone = true;
      cDNA.mszDNA[currentDNACharacter++] = '\0';
    }
    else
    {
      if (cDNA.isValidBase(charData))
      {
        // add the DNA base to the current DNA string.
        cDNA.mszDNA[currentDNACharacter++] = charData;
      }
      else
      {
 
        // this line has errors.
        // eat until we hit whitespace.
        // first fill in the \0

        cDNA.mszDNA[currentDNACharacter++] = '\0';

        while (!bDone && in.get(charData))
        {
          if (isspace(charData))
          {
            // found a whitespace so we reached the end of 
            // a DNA string
            bDone = true;
          }
        }


      }

    }
  }
  return in;
}

//****************************************************************************
// Method:	    isValidBase
//
// Description:	Determine if a character is a valid DNA base
//
// Parameters:  ch - the character to check
//
// Returned:	  bool - true or false to denote whether a the base is valid
//***************************************************************************

bool DNA::isValidBase(char ch) const
{
  bool bResult = false;

  switch (ch)
  {
  case ADENINE:
  case THYMINE:
  case GUANINE:
  case CYTOSINE:
    bResult = true;
  }
  return bResult;
}

//****************************************************************************
// Function:	  operator<< (friend of the class)
//
// Description:	Display a DNA string to a stream.  
//
// Parameters:  out - the stream to write to
//              cDNA - the DNA to write
//
// Returned:	  ostream& - the stream written to
//***************************************************************************

ostream& operator<<(ostream & out, const DNA &cDNA)
{
  int dnaLength = cDNA.getLength();
  for (int k = 0; k < dnaLength; k++)
  {
    out << cDNA.mszDNA[k];
  }
  return out;
}

//****************************************************************************
// Method:	    pstat
//
// Description:	Calculate the P-Stat similarity metric between the current
//              DNA object and the DNA object provided as a parameter
//
// Parameters:  otherDNA - the other DNA object to use in the calculation
//
// Returned:	  double - the value of the P-Stat similarity metric
//***************************************************************************

double DNA::pstat(const DNA &cOtherDNA) const
{
  double differences = 0;
  int dnaLength = getLength();
  int otherDNALength = cOtherDNA.getLength();

  if (dnaLength != otherDNALength)
  {
    return -1.0;
  }

  for (int k = 0; k < dnaLength; k++)
  {
    if (mszDNA[k] != cOtherDNA.mszDNA[k])
    {
      differences++;
    }
  }
  return differences / dnaLength;

}

//****************************************************************************
// Method:	    getLength
//
// Description:	Determine the length of the DNA strand. This requires the
//              strand in mszDNA to be NULL terminated
//
// Parameters:  None
//
// Returned:	  int - the length
//***************************************************************************

int DNA::getLength() const
{
  int length = 0;

  for (int i = 0; i < MAX_BASES + 1; i++)
  {
    if (mszDNA[i] == '\0')
    {
      length = i;
      i = MAX_BASES + 1;
    }
  }
  return length;
}


//****************************************************************************
// Method:	    operator==
//
// Description:	Determine if two DNA strands are the same
//
// Parameters:  cOtherDNA - the other DNA strand to compare against
//
// Returned:	  bool - true if the DNA strands match, false otherwise
//***************************************************************************

bool DNA::operator==(const DNA &cOtherDNA) const
{
  bool bResult = true;

  if (getLength() != cOtherDNA.getLength())
  {
    bResult = false;
  }
  else
  {
    for (int i = 0; i < getLength(); i++)
    {
      if (mszDNA[i] != cOtherDNA.mszDNA[i])
      {
        bResult = false;
      }
    }
  }

  return bResult;
}

