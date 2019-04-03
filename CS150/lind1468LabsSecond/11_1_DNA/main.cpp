//******************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				11/5/13
// Class:				CS150-01
// Assignment:	Arrays, Files, and Character Processing
// Purpose:			Read a file and use arrays to display DNA letters forward and 
//							backward.
//******************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
	char dnaNext;	
	char dnaStrand[1000];
	char rnaStrand[1000];
	char rnaNext;
	char gcStrand;
	int dnaCount = 0;
	int gcCount = 0;
	int startValue = 0;
	double gcContent;
	const char T_STRAND = 'T';
	const char U_STRAND = 'U';
	const char A_STRAND = 'A';
	const char C_STRAND = 'C';
	const char G_STRAND = 'G';
	const double PERCENTAGE_CONVERTER = 100.00;

	ifstream inputFile;
	
	inputFile.open ("dna2.txt");
	if (inputFile.fail ())
	{
		cout << "Error Opening File" << endl;
		exit (EXIT_FAILURE);
	}

	cout << "******************" << endl << "* Bioinformatics *" << endl 
			 << "******************" << endl << endl;

	
	// Reading and Printing DNA Strand.
	cout << "DNA Strand: " << endl;
	inputFile.peek ();
	while (!inputFile.eof ())
	{
		inputFile.get (dnaNext);
		dnaStrand[dnaCount] = dnaNext;
		++dnaCount;
		cout <<  dnaNext;
		inputFile.peek ();
	}
	cout << endl << endl;

	// Constructing RNA.
	cout << "RNA Strand: " << endl;
	inputFile.peek ();
	for (int i = startValue; i < dnaCount; ++i)
	{
		rnaStrand[i] = dnaStrand[i];
		if (rnaStrand[i] == T_STRAND)
		{
			rnaStrand[i] = U_STRAND;
		}
		cout << rnaStrand[i];
		inputFile.peek ();
	}
	cout << endl << endl;

	// Reverse Complement.
	cout << "Reverse Compliment: " << endl;
	for (int i = --dnaCount; i > startValue; --i)
	{
		rnaNext = dnaStrand[i];
		if (rnaNext == A_STRAND)
		{
			rnaNext = T_STRAND;
		}
		else if (rnaNext == T_STRAND)
		{
			rnaNext = A_STRAND;
		}
		else if (rnaNext == C_STRAND)
		{
			rnaNext = G_STRAND;
		}
		else if (rnaNext == G_STRAND)
		{
			rnaNext = C_STRAND; 
		}
		cout << rnaNext;
		}
		cout << endl << endl;

		// GC-content.
		cout << "GC-content: " << endl;
		for (int i = startValue; i < dnaCount; i++)
		{
			gcStrand = dnaStrand[i];
			if (gcStrand == G_STRAND || gcStrand == C_STRAND)
			{
				gcCount++;
			}
		}
		double gcDouble;
		double dnaDouble;
		gcDouble = static_cast<double>(gcCount);
		dnaDouble = static_cast<double>(dnaCount);

		gcContent = (gcDouble / dnaDouble) * PERCENTAGE_CONVERTER;


		cout << fixed << setprecision(2) << gcContent << "%" << endl << endl;
		return EXIT_SUCCESS;
}
		

	