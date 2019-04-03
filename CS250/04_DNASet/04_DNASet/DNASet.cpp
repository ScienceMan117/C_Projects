//**************************************************************************** 
// File name:	DNASet.cpp
// Author:		Aidan Lindsey
// Date:		3/11/2016
// Class:		CS 250
// Assignment:  04_DNASet
// Purpose:		Implement the DNA class
//****************************************************************************
#include <iostream>
#include <istream>
#include "DNASet.h"
#include <fstream>
#include <set>
#include <string>

using namespace std;

//****************************************************************************
// Constructor:	DNASet
//
// Description:	Initialize the mNumberDNAStrands to 0
//
// Parameters:	none
//
// Returned:    none
//***************************************************************************
DNASet::DNASet ()
{
    mNumberDNAStrands = 0;
}
//****************************************************************************
// Method:	    
//
// Description:	
//
// Parameters:  
//
// Returned:	  
//***************************************************************************
void DNASet::addDNAStrand (const DNA & DNAObject)
{
    if (MAX_STRANDS > mNumberDNAStrands && !contains (DNAObject))
    {
        mDNAArray[mNumberDNAStrands] = DNAObject;
        mNumberDNAStrands++;
    } 
}
//****************************************************************************
// Method:	    
//
// Description:	
//
// Parameters:  
//
// Returned:	  
//***************************************************************************
bool DNASet::contains (const DNA & DNAObject) const
{
    bool bResult = false;
    for (int i = 0; i < mNumberDNAStrands; i++)
    {
        if (mDNAArray[i].operator==(DNAObject) == true)
        {
            bResult = true;
        }           
    }
    return bResult;
}

//****************************************************************************
// Method:	    
//
// Description:	
//
// Parameters:  
//
// Returned:	  
//***************************************************************************
DNASet DNASet::set_union (const DNASet & cDNASetObject) const
{
    DNASet cNewDNASet;

    for (int i = 0; i < cDNASetObject.mNumberDNAStrands; i++)
    {
        cNewDNASet.addDNAStrand (cDNASetObject.mDNAArray[i]);
    }
    for (int k = 0; k < mNumberDNAStrands; k++)
    {
        cNewDNASet.addDNAStrand (mDNAArray[k]);
    }

    return cNewDNASet;
}
//****************************************************************************
// Method:	    
//
// Description:	
//
// Parameters:  
//
// Returned:	  
//***************************************************************************
DNASet DNASet::set_intersection (const DNASet & cDNASetObject) const
{
    DNASet cNewDNAObject;

    return cNewDNAObject;
}
//****************************************************************************
// Method:	    
//
// Description:	
//
// Parameters:  
//
// Returned:	  
//***************************************************************************
ostream& operator<<(ostream &out, const DNASet & cDNASetObject)
{
    int dnaLength = cDNASetObject.mDNAArray[cDNASetObject.mNumberDNAStrands].getLength();
    for (int k = 0; k < cDNASetObject.mNumberDNAStrands; k++)
    {
        out << cDNASetObject.mDNAArray[k];
    }
    return out;
}
////****************************************************************************
// Method:	    
//
// Description:	
//
// Parameters:  
//
// Returned:	  
//***************************************************************************
istream& operator>>(istream &in, DNASet &cDNASetObject)
{
    char charData = in.get();
    int counter = 0;

    while (!in.eof () && counter < cDNASetObject.MAX_STRANDS)
    {
        while (('\n' != charData && EOF != charData) && counter < cDNASetObject.MAX_STRANDS)
        {
            cDNASetObject.mDNAArray[counter] = charData;
            counter++;
        }
        charData = in.get ();
        counter++;
    }
    return in;
}

