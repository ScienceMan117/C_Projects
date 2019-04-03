//*****************************************************************************
// File Name:	 DNA.cpp
// Author:		 Aidan Lindsey
// Date:		 2/15/2016
// Class:		 CS250-02
// Assignment:	 Assignment 01_DNA
// Purpose:		  
//						
// Hours:		   
//*****************************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_BASES = 80;
const int MAX_STRINGS = 20;

void printDNALength(istream &inFile, ostream &out, char szDNAArray[][MAX_BASES]);
int readDNAArray(istream &inFile, char szDNAArray[][MAX_BASES]);

/*void printDNAString(char szDNAArray[][MAX_STRINGS]);*/

/*int compareStrings(char szDNAArray[][MAX_STRINGS]);*/
int main()
{
	ifstream inputFile;
	ofstream outputFile;

	char szDNAArray[MAX_STRINGS][MAX_BASES];
	/*char szDNAKey[MAX_STRINGS];*/
	ifstream inFile;

	inFile.open("dnastrings.txt");

	if (!inFile)
	{
		cout << "Error: could not open dnastrings,.txt\n\n";
		return EXIT_FAILURE;
	}
	
	printDNALength(inFile, cout, szDNAArray);
	/*while (EOF != readDNAInit(inFile, szDNAInit))
	{
		
	
	}
		*/

	inFile.close();
	return EXIT_SUCCESS;
}
/******************************************************************************
Function:     

Description:  


Parameters:   

Returned:     
******************************************************************************/
void printDNALength(istream &inFile, ostream &out, char szDNAArray[][MAX_BASES])
{
	int length = readDNAArray(inFile, szDNAArray);
	cout << "DNA" << " " << "(Length=" << length;
	cout << ")" << " " << ":" << endl;
	for (int i = 0; i < length; i++)
	{
		out << szDNAArray[MAX_STRINGS][i];
	}
}
/******************************************************************************
Function:

Description:
'A' != szDNAArray[i][MAX_BASES] || 'C' != szDNAArray[i][MAX_BASES]
|| 'G' != szDNAArray[i][MAX_BASES] || 'T' != szDNAArray[i][MAX_BASES]

Parameters:

Returned:
******************************************************************************/
void getUserKey(ifstream &inFile, char szDNAArray[][MAX_BASES], int MAX_BASES)
{

	
}
/******************************************************************************
Function:

Description:


Parameters:

Returned:
******************************************************************************/
int readDNAArray(istream &inFile, char szDNAArray[][MAX_BASES])
{
	char base = inFile.get();
	int i = 0;
	int j = 0;
	int counter = 0;
	while (base != EOF && j < MAX_STRINGS)
	{
		while (('\n' != base && EOF != base) && i < MAX_BASES)
		{
			szDNAArray[j][i] = base;
			i++;
			base = inFile.get();
			if (j == 0)
			{
				counter++;
			}
		}
		base = inFile.get();
		j++;
	}
	szDNAArray[i][j] = '\0';
	return counter;
}
