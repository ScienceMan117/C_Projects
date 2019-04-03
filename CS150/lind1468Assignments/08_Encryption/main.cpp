//*****************************************************************************
// File Name:	 main.cpp
// Author:		 Aidan Lindsey
// Date:			 11/25/2013
// Class:			 CS150-01
// Assignment: Assignment 08_Encryption
// Purpose:		 Take a plan text file and produce an encypted file using 
//						 functions, arrays, and 2d arrays.
// Hours:		   7
//*****************************************************************************
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Variable that must be declared to have the 2D arrays to work
const int LETTERS_IN_ALPHABET = 26;

// Functions that will be used in the Encryption program
void printHeading (const char heading[]);
void getMappingData (int &numberOfMappings, char key[]);
bool isAllUppercase (const char keys[], int numkeys);
void openFileForRead (ifstream &inputFile, const char message[]);
void openFileForWrite (ofstream &outputFile, const char message[]);
void constructMappingArray (char mappingArray[][LETTERS_IN_ALPHABET], 
														const char keyArray[], int numberOfMappings);
void printMappingArray (const char mappingArray[][LETTERS_IN_ALPHABET],
												int numberOfMappings);
char decodeCharacter (char ciphertextCharacter, 
											const char mappingArray[][LETTERS_IN_ALPHABET],
											int numberOfMappings);
char encodeCharacter (char plaintextCharacter, 
											const char mappingArray[][LETTERS_IN_ALPHABET],
											int numberOfMappings);

// List Global Constants
const char STARTING_LETTER = 'A';
const char ENDING_LETTER = 'Z';
const int BOTTOM_VALUE = 0;
const int MAX_FILE_NAME = 32;
const int MAXIMUM_KEY = 25;
const int MINIMUM_KEY = 2;
const int COLUMN_CONVERTER = 1;
const int ENCRYPTION_MAXIMUM = 1000;
/******************************************************************************
Function:     main

Description:  Displays the heading, calls the functions.

Parameters:   none

Returned:     Exit Status
******************************************************************************/
int main ()
{
	// List inputFile and outFile text files
	ifstream inputFile;
	ofstream outputFile;

	// List variables that will be used in int main () only
	const char ENCODE = 'E';
	const char DECODE = 'D';
	const char QUIT = 'Q';
	char ciphertextCharacter;
	char plaintextCharacter;
	char heading[ENCRYPTION_MAXIMUM] = "Encryption";
	int numberOfMappings = BOTTOM_VALUE;
	char key [MAXIMUM_KEY];
	char messagePlain[] = "Enter inputFile name: ";
	char messageCipher[] = "Enter outputFile filename: ";
	char mappingArray[MAXIMUM_KEY][LETTERS_IN_ALPHABET];
	char userChoice;

	// Call the functions
	printHeading (heading);
	
	// Continue to have the user Encode or Decode the program until the user 
	// inputs Q)uit
	do 
	{
	// Have the user input Encode, or Decode 
		do
		{
		cout << "Enter E)ncode, D)ecode, Q)uit: ";
		cin >> userChoice;
		} while (userChoice != ENCODE && userChoice != DECODE 
						 && userChoice != QUIT);

		// Encode the message from plaintext.txt
		if (userChoice == ENCODE)
		{
			getMappingData (numberOfMappings, key);
			openFileForRead (inputFile, messagePlain);
			openFileForWrite (outputFile, messageCipher);
			constructMappingArray(mappingArray, key, numberOfMappings);

			// Continue to pull characters out of plaintext.txt, while checking to
			// make sure that the characters are uppercase, until all the characters
			// and whitespaces have been read. Then place the characters in the 
			// inputFile
			while (!inputFile.eof())
			{
				inputFile.get (plaintextCharacter);
				if (plaintextCharacter >= STARTING_LETTER 
						&& plaintextCharacter <= ENDING_LETTER)
				{
					plaintextCharacter = encodeCharacter (plaintextCharacter, 
																								mappingArray, numberOfMappings);
					outputFile << plaintextCharacter;
				}
				inputFile.peek();
			}	
			inputFile.close();
			outputFile.close();
		}

		// Decode the message from ciphertext.txt
		else if (userChoice == DECODE)
		{
			getMappingData (numberOfMappings, key);
			openFileForRead (inputFile, messagePlain);
			openFileForWrite (outputFile, messageCipher);
			constructMappingArray(mappingArray, key, numberOfMappings);
			printMappingArray(mappingArray, numberOfMappings);
			inputFile.peek ();

			// Continue to pull characters out of ciphertext.txt, while checking to
			// make sure that the characters are uppercase, until all the characters
			// and whitespaces have been read. Then place the characters in the 
			// outputFile
			while (!inputFile.eof())
			{
				inputFile.get (ciphertextCharacter);
				if (ciphertextCharacter >= STARTING_LETTER 
						&& ciphertextCharacter <= ENDING_LETTER)
				{
					ciphertextCharacter = decodeCharacter (ciphertextCharacter, 
																								 mappingArray, 
																								 numberOfMappings);
					outputFile << ciphertextCharacter;
				}
			inputFile.peek();
			}	

			// Close the files so that the values in the text files are flushed out
			// and not stored
			inputFile.close();
			outputFile.close();
		}
	} while (userChoice != QUIT);
}
/******************************************************************************
Function:     printHeading

Description:  Prints the heading as displayed on the sample output of the 
							 previous page.

Parameters:   heading - array that contains the title of the program

Returned:     None
******************************************************************************/
void printHeading (const char heading[])
{
	// Display title of program when called
	cout << "*******************" << endl;
	cout << "* " << heading << endl;
	cout << "*******************" << endl << endl;
}

/******************************************************************************
Function:     getMappingData

Description:  Prompts the user for the number of mappings and keys as 
							 displayed on the same sample output

Parameters:   numberOfMappings - number of times program will incriment
							key - the number of letters the user inputs

Returned:     None
******************************************************************************/
void getMappingData (int &numberOfMappings, char key[])
{
	// Have the user continue to input mapping values until they input a valid
	// number 
	do
	{
		cout << "Enter number of mappings (2-25): ";
		cin >> numberOfMappings;
	} while (numberOfMappings < MINIMUM_KEY || numberOfMappings > MAXIMUM_KEY);

	// Have the user continue to input key values until they input a valid
	// set of keys
	do
	{
		cout << "Enter the " << numberOfMappings << " keys: ";
		cin >> key; 
	} while (static_cast<int>(strlen (key)) != numberOfMappings || 
					 !isAllUppercase(key, numberOfMappings));
}
/******************************************************************************
Function:     isAllUppercase

Description:  Determines whether or not the user typed a uppercase letter or 
							 lower case letter, and returns the letter

Parameters:   numberOfMappings - number of times program will incriment
							key - number of letters the user inputs

Returned:     None
******************************************************************************/
bool isAllUppercase (const char keys[], int numkeys)
{
	bool bVal = true;

	// Evaluate the letters in the function getMappingData and make sure that all
	// the letters are uppercase
	for (int uppercaseLetters = BOTTOM_VALUE; uppercaseLetters < numkeys; 
			 ++uppercaseLetters)
	{
		if (keys[uppercaseLetters] < STARTING_LETTER || 
				keys[uppercaseLetters] > ENDING_LETTER)
		{
			bVal = false;
		}
	}
	return bVal;
}
/******************************************************************************
Function: openFileForRead    

Description: Accepts a message to be displayed, then prompts the user to enter  
						a plaintext file validating that the file exists and is open.	 

Parameters: inputFile - The file the user inputs that is read in resources. 
												Read as plaintext.txt
						messagePlain - The message that is displayed for the user to input	
													 a valid file name

Returned: None   
******************************************************************************/
void openFileForRead (ifstream &inputFile, const char messagePlain[])
{
	// List the variables in the function openFileForRead
	char plainName[MAX_FILE_NAME];

	// Have the user continue to input a file name until a valid file is choosen
	do
	{
		cout << messagePlain;
		cin >> plainName;
		inputFile.open (plainName);
	} while (inputFile.fail ());
}
/******************************************************************************
Function: openFileForWrite     

Description: Accepts a message to be displayed, then prompts the user to enter  
						 a ciphertext file validating that file exists, and we are writing
						 to the file

Parameters: outputFile - The file the user inputs that is read in resources. 
												 Read as ciphertext.txt
						messageCipher - The message that is displayed for the user to out a 
														valid file name

Returned: None    
******************************************************************************/
void openFileForWrite (ofstream &outputFile, const char messageCipher[])
{
	// List the variables for the function openFileForWrite
	char plainName[MAX_FILE_NAME];

	// Have the user continue to output a file name until a valid file is choosen
	do
	{
		cout << messageCipher;
		cin >> plainName;
		outputFile.open (plainName);
	} while (outputFile.fail ());
}
/******************************************************************************
Function: constructMappingArray   

Description: Using the keyArray and numberOfMappings, you are to create the 
						 mappingArray as discussed above
							 
Parameters: mappingArray - The array that contains the coded and uncoded 
													 letters based on the keyArray and the 
													 numberOfMappings

						keyArray - The array that contains the letters that the user 
											 outputted	
						numberOfMappings - The number of mappings the user outputted and 
															 also the number of iterations that will happen
															 in the mappingArray
Returned:	None										 
******************************************************************************/
void constructMappingArray (char mappingArray[][LETTERS_IN_ALPHABET], 
														const char keyArray[], int numberOfMappings)
{
	// List the variables in the function constructMappingArray
	char letterCount;

	// Have the rowCount and columnCount keep going incrementing until the values
	// reach the parameters
	for (int rowCount = BOTTOM_VALUE; rowCount <= numberOfMappings; ++rowCount)
	{
		if (rowCount == BOTTOM_VALUE)
		{
			letterCount = STARTING_LETTER;
		}
		else
		{ 
			letterCount = keyArray[rowCount - COLUMN_CONVERTER];
		}
		for (int columnCount = BOTTOM_VALUE; columnCount < LETTERS_IN_ALPHABET; 
				 ++columnCount)
		{
			mappingArray[rowCount][columnCount] = letterCount;
			if (letterCount == ENDING_LETTER)
			{
				letterCount = STARTING_LETTER;
			}
			else
			{
				letterCount++;
			}
		}
	}
}
/******************************************************************************
Function: printMappingArray    

Description: This function is simply for debugging. After creating the   
						 mappingArray, print out the array to make sure you have a correct
						 mappingArray

Parameters: mappingArray - The array that contains the coded and uncoded 
													 letters based on the keyArray and the 
													 numberOfMappings
						numberOfMappings - The number of mappings the user outputted and 
															 also the number of iterations that will happen
															 in the mappingArray
							
Returned: None    
******************************************************************************/
void printMappingArray (const char mappingArray[][LETTERS_IN_ALPHABET],
												int numberOfMappings)
{
	// Display the mappingArray, until rowCount and columnCount reach the
	// numberOfMappings
	for(int rowCount = BOTTOM_VALUE; rowCount <= numberOfMappings; ++rowCount)
	{
		for(int columnCount = BOTTOM_VALUE; columnCount < LETTERS_IN_ALPHABET; 
			  ++columnCount)
		{
			mappingArray[rowCount][columnCount];
		}
		cout << endl;
	}
}
/******************************************************************************
Function: decodeCharacter    

Description: Using the number of mappings and the mappingArray, this function 
						 takes an encoded character and returns a decoded character using
						 the process describe above

Parameters:	ciphertextCharacter - the variable that will decipher the letters
																	and input the characters in ciphertext.txt
						mappingArray - The array that contains the coded and uncoded 
													 letters based on the keyArray and the 
													 numberOfMappings
						numberOfMappings - The number of mappings the user outputted and 
															 also the number of iterations that will happen
															 in the mappingArray
							
Returned: decodeCharacter    
******************************************************************************/
char decodeCharacter (char ciphertextCharacter, 
											const char mappingArray[][LETTERS_IN_ALPHABET],
											int numberOfMappings)
{
	// Decode a character from ciphertext.txt using the mappingArray, 
	// numberOfmappings and place the character or whitespace into 
	// ciphertextCharacter
	for (int decodeCount = numberOfMappings; decodeCount >= BOTTOM_VALUE;
			 --decodeCount)
	{
		int mappingCount = BOTTOM_VALUE;
		while (mappingArray[decodeCount][mappingCount] != ciphertextCharacter)
		{
			++mappingCount;
		}
		ciphertextCharacter = mappingArray[BOTTOM_VALUE][mappingCount];
	}
	// Return the individual character to int main ()
	return ciphertextCharacter;
}
/******************************************************************************
Function: encodeCharacter    

Description: Using the number of mappings and the mappingArray, this function 
						 takes an encoded character and returns a encoded character using
						 the process describe above

Parameters:	plaintextCharacter - the variable that will decipher the letters
																	and input the characters in plaintext.txt
						mappingArray - The array that contains the coded and uncoded 
													 letters based on the keyArray and the 
													 numberOfMappings
						numberOfMappings - The number of mappings the user outputted and 
															 also the number of iterations that will happen
															 in the mappingArray
							
Returned: encodeCharacter    
******************************************************************************/
char encodeCharacter (char plaintextCharacter, 
											const char mappingArray[][LETTERS_IN_ALPHABET],
											int numberOfMappings)
{
	// Encode a character from plaintext.txt using the mappingArray, 
	// numberOfmappings and place the character or whitespace into 
	// plaintextCharacter
	for (int encodeCount = BOTTOM_VALUE; encodeCount <= numberOfMappings; 
			 ++encodeCount)
	{
		int mappingCount = BOTTOM_VALUE;
		while (mappingArray[BOTTOM_VALUE][mappingCount] != plaintextCharacter)
		{
			++mappingCount;
		}
		plaintextCharacter = mappingArray[encodeCount][mappingCount];
	}
	// Return the individual character to int main ()
	return plaintextCharacter;
}