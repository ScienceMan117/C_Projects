//*****************************************************************************
// File Name:	 main.cpp
// Author:		 Aidan Lindsey
// Date:			 11/17/2013
// Class:			 CS150-01
// Assignment: Quiz Grade Report
// Purpose:		 Read a text file and print information from each student using
//						 functions and arrays.
// Hours:		   5   
//*****************************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// List function names.
void displayHeading (string heading);
void readQuizAnswers (ifstream &inputGradeData, bool bAnswers[], 
											int numAnswers);
double calculateQuizScore (bool bAnswers[], bool bStudentAnswers[], 
												 int numAnswers);
void displayQuizAnswers (bool bQuizAnswers[], int numAnswers);
void displayQuizReport (string id, bool bAnswer[], bool bStudentAnswers[],
												int numAnswers, double quizScore);

// List Global variables
const int FILE_INPUT_MAX = 25;
const int FILE_READER_START = 0;
const double DOUBLE_CONVERTER = 100.00;
/******************************************************************************
 Function:     main

 Description:  Displays the student information.

 Parameters:   None

 Returned:     Exit Status
******************************************************************************/
int main ()
{
	// List variables that will run in int main ()
	string heading;
	bool quizKey [FILE_INPUT_MAX];
	bool studentsScore [FILE_INPUT_MAX];
	int quizAnswers;
	double quizScore;
	string (studentId);
	ifstream inputFile;
	inputFile.open ("quiz7.txt");
	
	// If file is unable to open then exit program
	if (inputFile.fail ())
	{
		exit (EXIT_FAILURE);
	}

	// Read in file to read as quiz answers
	inputFile >> quizAnswers;

	// Compute function readQuizAnswers for the quiz key
	readQuizAnswers (inputFile, quizKey, quizAnswers);

	// Display Heading at top of the program
	displayHeading (heading);
	cout << endl;

	// Have the file read the student ID, compute the function readQuizAnswers
	// for the students, calculate the students quiz score, and display the 
	// students ID, students score, quiz answers, and the students score,
	// while there is still data to be read from the file quiz7.txt
	inputFile.peek ();
	while (!inputFile.eof())
	{
		inputFile >> studentId;
		readQuizAnswers (inputFile, studentsScore, quizAnswers);
	  quizScore = calculateQuizScore (quizKey, studentsScore, quizAnswers);
		displayQuizReport (studentId, quizKey, studentsScore,
												quizAnswers, quizScore);
		inputFile.peek ();
	}

	return EXIT_SUCCESS;

}
/******************************************************************************
 Function:     displayHeading

 Description:  Prints the heading passed passed to the function to the screen
							 
 Parameters:   heading - The title of the program

 Returned:     None
******************************************************************************/
void displayHeading (string heading)
{
	cout << "*****************************" << endl;
	cout << "* Quiz Grade Report" << endl;
	cout << "*****************************" << endl;
}

/******************************************************************************
 Function:     readQuizAnswers

 Description:  Reads in numAnswers boolean values from inputGradeData and 
							 stores the answers in an array called bAnswers
							 
 Parameters:   inputFile - the values from the file quiz7.txt
							 bAnswers - the array for the answers
							 numAnswers - the maximum number of characters that can be read

 Returned:     None
******************************************************************************/
void readQuizAnswers (ifstream &inputFile, bool bAnswers[], 
											int numAnswers)
{
	for (int fileReader = FILE_READER_START; fileReader < numAnswers; 
		   ++fileReader)
	{
		inputFile >> bAnswers[fileReader];
	}
}
/******************************************************************************
 Function:     calculateQuizScore

 Description:  Calculates one student's quiz score and returns the score
							 through the function.
							 
 Parameters:   bAnswers - the array that contains the answer key
							 bStudentAnswers - the array the contains the student answers
							 numAnswers - the maximum number of characters that can be read

 Returned:     studentScore
******************************************************************************/
double calculateQuizScore (bool bAnswers[], bool bStudentAnswers[], 
				int numAnswers)
{
	// List variables for the function calculateQuizScore
	double answersCorrect = 0.00;
	double studentScore;
	
	// Calculate the total correct answers from a student
	for (int fileReader = FILE_READER_START; fileReader < numAnswers;
		   ++fileReader)
	{
		if (bStudentAnswers[fileReader] == bAnswers[fileReader])
		{
			++answersCorrect;
		}
	}

	// Calculate the student score percentage
	studentScore = (answersCorrect / static_cast<double>(numAnswers))
		              * DOUBLE_CONVERTER;

	// Return the students score to int main ()
	return studentScore;
}
/******************************************************************************
 Function:     displayQuizAnswers

 Description:  Prints to the screen the values in the array bQuizAnswers where
							 each answer is seperated by two spaces.
							 
 Parameters:   bQuizAnswers - an array that contains the answers for the key
							 and the students
							 numAnswers - the maximum number of characters that can be read

 Returned:     None
******************************************************************************/
void displayQuizAnswers (bool bQuizAnswers[], int numAnswers)
{
	for (int fileReader = FILE_READER_START; fileReader < numAnswers; 
		   ++fileReader)
	{
		cout << bQuizAnswers[fileReader] << "  ";
	}
}
/******************************************************************************
 Function:     displayQuizAnswers

 Description:  Prints to the screen the values in the array bQuizAnswers where
							 each answer is seperated by two spaces.
							 
 Parameters:   id - the student id read from the file quiz7.txt
							 bAnswer - array that contains the key answers
							 bStudentAnswers - array that contains the answers for each 
							 student
							 numAnswers - the maximum number of characters that can be read
							 quizScore - the students score percentage

 Returned:     None
******************************************************************************/
void displayQuizReport (string id, bool bAnswer[], bool bStudentAnswers[],
												int numAnswers, double quizScore)
{
		cout << "Student ID: " << id << endl;
		cout << "Grade: " << fixed << setprecision(2) << quizScore << "%";
		cout << endl << endl << "Correct Answers: "; 
		displayQuizAnswers (bAnswer, numAnswers);
		cout << endl << "Student Answers: ";
		displayQuizAnswers (bStudentAnswers, numAnswers);
		cout << endl << endl << endl << endl;
}