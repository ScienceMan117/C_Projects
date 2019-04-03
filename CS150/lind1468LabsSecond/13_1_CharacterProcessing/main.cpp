#include <iostream>
#include <fstream>

using namespace std;

const int MAX_FILE_NAME = 32;

const int MAX_VOWELS = 5;
const char VOWELS[] = {'A', 'E', 'I', 'O', 'U'};
const int MAX_CONSONANTS = 21;
const char CONSONANTS[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M',
													 'N', 
													 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 
													 'Z'};
int search (const char searchArray[], int numCharacters, char character);
void removeExtraSpace (ifstream &inputData);

int main ()
{
	ifstream inputData;
	ofstream outputData;
	char inputName[MAX_FILE_NAME];
	char outputName[MAX_FILE_NAME];
	char letter;
	int numVowels = 0;
	int numConsonants = 0;

	//TODO: 1) Write the C++ code to open a file for reading
	//      Prompt the user for the filename and place the name in inputName
	//      Validate the input until the user enters a valid filename

	do
	{
		cout << "Enter a valid inputName file: ";
		cin >> inputName;
		inputData.open (inputName);
	} while (inputData.fail ());

	//TODO: 2) Write the C++ code to open the file for writing
	//      Prompt the user for the filename and place the name in outputName
	//      Validate the input until the user enters a valid filename

	do
	{
		cout << "Enter a valid outputName file: ";
		cin >> outputName;
		outputData.open (outputName);
	} while (inputData.fail ());


	//TODO: 3) Make an exact copy of the file inputName in the file outputName
	//      such that all lowercase letters are converted to uppercase
	
	inputData.peek ();
	while (!inputData.eof ())
	{
		inputData.get (letter);
		if (letter >= 'a' && letter <= 'z')
		{
			letter = letter + ('A' - 'a');
		}
		
		outputData << letter;
		if (search (VOWELS, MAX_VOWELS, letter) != -1)
		{
			numVowels++;
		}
		else if (search (CONSONANTS, MAX_CONSONANTS, letter) != -1)
		{
			numConsonants++;
		}
		inputData.peek ();
	}
	inputData.close ();
	outputData.close ();
	
	//TODO: 4) SHOW THE INSTRUCTOR OR TUTOR YOUR SOLUTION

	//TODO: 5) Complete the function search below that accepts an array, an array
	//      size, and a character to be searched for. Return -1 if the character
	//      is not found; otherwise, return the index of where the character
	//      was found in the array

	//TODO: 6) After writing to the file in 3), add additional code to count
	//      the number of vowels written to the file. You will need to use the
	//      function search to determine whether a character is a vowel or not.
	//      After the files are closed, print the number of vowels to the screen

	cout << numVowels << endl;

	// 7) After writing to the file in 3), add additional code to count
	//      the number of consonants written to the file. You will need to use the
	//      function search to determine whether a character is a consonant or not
	//      After the files are closed, print the number of consonants to the 
	//      screen

	cout << numConsonants << endl;

	//TODO: 8) SHOW THE INSTRUCTOR OR TUTOR YOUR SOLUTION

	// OPTIONAL

	//TODO: 9) peek sets EOF to true if the current stream pointer is at the EOF
	//      peek also returns the next character pointed to in the input stream
	//      without removing the character from the stream. Write the function
	//      removeExtraSpace such that if the next character in the stream is a
	//      space, then read and remove the character. Continue reading and 
	//      removing consecutive characters from the input stream.

	//TODO: 10) If a single character is read in section 3), then send that 
	//      character to the output file and call removeExtraSpace which should
	//      eat consecutive spaces from the input file

	//TODO: 11) SHOW THE INSTRUCTOR OR TUTOR YOUR SOLUTION

	return EXIT_SUCCESS;
}

int search (const char searchArray[], int numCharacters, char character)
{
	for (int i = 0; i < numCharacters; ++i)
	{
		if (searchArray[i] == character)
		{
			return i;
		}
	}
	return -1;
		
}

void removeExtraSpace (ifstream &inputData)
{
}p[=