//*****************************************************************************
// File Name:  Course.cpp
// Author:	   Aidan Lindsey
// Date:	   2/29/2016
// Class:	   CS250-02
// Assignment: Assignment 02_Structs
// Purpose:	   Implements the functions created in the Course.h that will be 
//			   called in Struct.cpp
//*****************************************************************************
#include "Course.h"
#include <istream>
#include <iostream>
/******************************************************************************
Function:     displayHeading

Description:  Displays the heading for the program

Parameters:   none

Returned:     None
******************************************************************************/
void displayHeading()
{
	cout << "**************************" << endl;
	cout << "PACIFIC UNIVERSITY COURSES" << endl;
	cout << "**************************" << endl;
}
/******************************************************************************
Function:     displayChoices

Description:  Displays the options avaiable to the user to input

Parameters:   none

Returned:     None
******************************************************************************/
void displayChoices()
{
	cout << "1. Print all courses" << endl;
	cout << "2. Print one course" << endl;
	cout << "3. Add a student to a course" << endl;
	cout << "4. Quit" << endl << endl;
}
/******************************************************************************
Function:     userInput

Description:  Displays Option to allow the user to input the option they want
			  to do.

Parameters:   int choice - the choice the user inputs to decide what option to
						   do

Returned:     choice 
******************************************************************************/
int userInput(int choice)
{
	cout << "Option: ";
	cin >> choice;
	return choice;
}
/******************************************************************************
Function:     numberClasses

Description:  Counts the number of rows in the Course.txt file and returns the
			  number of rows

Parameters:   istream &inFile - passes the file information from Course.txt to
								be read and used

Returned:     counter
******************************************************************************/
int numberClasses(istream &inFile)
{
	string line;
	int counter = 0;
	while (getline(inFile, line))
	{
		++counter;
	}
	return counter;
}
/******************************************************************************
Function:     readClass

Description:  Reads the values in the Course.txt file and initializes them into
			  the struct object Class.

Parameters:   istream &inFile- passes the file information from Course.txt to
							   be read and used
			  Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class 
									  capacity, and class enrollment 
			  int classNumber - the total number of classes from the file

Returned:     None
******************************************************************************/
void readClass(istream &inFile, Class sClassList[100], int classNumber)
{
	for (int i = 0; i < classNumber; i++)
	{
		inFile >> sClassList[i].mSubject >> sClassList[i].mNumber >> sClassList[i].mCapacity
			>> sClassList[i].mEnrollment;
	}

}
/******************************************************************************
Function:     AllClassInfo

Description:  Prints the the screen all the class information in the struct

Parameters:   ostream &out - allows the user to output any information that 
							 can change
			 Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class
									  capacity, and class enrollment
			 int classNumber - the total number of classes from the file

Returned:     None
******************************************************************************/
void AllClassInfo(ostream &out, Class sClassList[100], int classNumber)
{
	int availability = 0;

	for (int i = 0; i < classNumber; i++)
	{
		cout << sClassList[i].mSubject << " ";
		cout << sClassList[i].mNumber << " ";
		cout << "Cap: " << sClassList[i].mCapacity << " ";
		availability = sClassList[i].mCapacity - sClassList[i].mEnrollment;
		cout << "Available: " << availability << endl;
	}
	cout << endl;
}
/******************************************************************************
Function:     printClassInfo

Description:  Prints the class information from one class

Parameters:   ostream &out - allows the user to output any information that
							 can change
			  Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class
									  capacity, and class enrollment
			  int specificClass - holds a recorn of a specific class data
Returned:     None
******************************************************************************/
void printClassInfo(ostream &out, Class sClassList[100], int specificClass)
{
	int availability = 0;

	cout << sClassList[specificClass].mSubject << " ";
	cout << sClassList[specificClass].mNumber << " ";
	cout << "Cap: " << sClassList[specificClass].mCapacity << " ";
	availability = sClassList[specificClass].mCapacity - sClassList[specificClass].mEnrollment;
	cout << "Available: " << availability;
	cout << endl << endl;
}
/******************************************************************************
Function:     UserPrefix

Description:  Allows the user to input a class Prefix

Parameters:   ostream &out - allows the user to output any information that
							 can change
			  istream &in - allow the user input any information that can 
							change

Returned:     Prefix
******************************************************************************/
string UserPrefix(ostream &out, istream &in)
{
	string Prefix;
	cout << "Prefix: ";
	cin >> Prefix;
	return Prefix;
}
/******************************************************************************
Function:     UserNumber

Description:  Allows the user to input a class number

Parameters:   ostream &out - allows the user to output any information that
							can change
			  istream &in - allow the user input any information that can
							change

Returned:     Number
******************************************************************************/
int UserNumber(ostream &out, istream &in)
{
	int Number = 0;
	cout << "Number: ";
	cin >> Number;
	cout << endl;
	return Number;
}
/******************************************************************************
Function:     lookForClass

Description:  Looks for a specific class in the struct Class and returns true
			  if the class is there and returns false if the class is not in
			  the struct

Parameters:   Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class
									  capacity, and class enrollment
			  string Prefix - user inputed class Prefix
			  int Number - User inputed class number
			  int classNumber - the total number of classes from the file

Returned:     bool
******************************************************************************/
bool lookForClass(Class sClassList[100], string Prefix, int Number, int classNumber)
{
	bool classExists;
	classExists = false;

	for (int counter = 0; counter < classNumber; counter++)
	{
		if (sClassList[counter].mSubject == Prefix)
		{
			if (sClassList[counter].mNumber == Number)
			{
				classExists = true;
			}
		}
	}
	if (classExists == false)
	{
		cout << "Course not found" << endl << endl;
	}
	return classExists;
}
/******************************************************************************
Function:     readSingleClass

Description:  Reads in a single class from the Class struct that the user 
			  inputed a class prefix and class number for

Parameters:   Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class
									  capacity, and class enrollment
			  string Prefix - user inputed class Prefix
			  int Number - User inputed class number
			  int classNumber - the total number of classes from the file

Returned:     specificClass
******************************************************************************/
int readSingleClass(Class sClassList[100], string Prefix, int Number, int classNumber)
{
	int counter = 0;
	int specificClass = 0;
	while (counter < classNumber)
	{
		if (sClassList[counter].mSubject == Prefix)
		{
			if (sClassList[counter].mNumber == Number)
			{
				specificClass = counter;
			}
		}
		counter++;
	}
	return specificClass;
}
/******************************************************************************
Function:     addStudent

Description:  Checks to make sure the number of people enrolled is lower than
			  the capacity of the class. If the people enrolled is lower than 
			  the capacity a student will be added to the enrolled to 
			  sClassList[100].mEnrollment. Then the availability is outputted.
			  If the number enrolled is equal to the capacity, a message is
			  outputted saying no more students can be added.


Parameters:   Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class
									  capacity, and class enrollment
			  ostream &out - allows the user to output any information that
							can change
			  istream &in - allow the user input any information that can
							change
			  int specificClass - user inputed specific class from the 
								  sClassList[100]

Returned:     None
******************************************************************************/
void addStudent(Class sClassList[100], istream &in, ostream &out, int specificClass)
{
	int availability = 0;

	if (sClassList[specificClass].mEnrollment < sClassList[specificClass].mCapacity)
	{
		sClassList[specificClass].mEnrollment = sClassList[specificClass].mEnrollment + 1;
		availability = sClassList[specificClass].mCapacity - sClassList[specificClass].mEnrollment;
		if (sClassList[specificClass].mEnrollment < sClassList[specificClass].mCapacity)
		{
			cout << sClassList[specificClass].mSubject << " ";
			cout << sClassList[specificClass].mNumber << " ";
			cout << "Cap: " << sClassList[specificClass].mCapacity << " ";
			cout << "Available: " << availability;
			cout << endl << endl;
			cout << ". . . < add more students to " << sClassList[specificClass].mSubject << " ";
			cout << sClassList[specificClass].mNumber << ">" << endl << endl;
		}
	}
	if (sClassList[specificClass].mEnrollment == sClassList[specificClass].mCapacity)
	{
		cout << "Course already full." << endl << endl;
	}

}
/******************************************************************************
Function:     improperData

Description:  Checks to make sure the information in the file follows the
			  rules of the program. Returns true if the information from the
			  the file is valid and returns false if the information is invalid

Parameters:   Class sClassList[100] - Object Array of Stuct Class that holds
									  class subject, class number, class
									  capacity, and class enrollment
			  int classNumber - the total number of classes from the file
Returned:     properData
******************************************************************************/
bool improperData(Class sClassList[100], int classNumber)
{
	bool properData = true;

	if (classNumber > 10)
	{
		properData = false;
	}

	for (int i = 0; i < classNumber; i++)
	{
		if (sClassList[i].mSubject != "CS")
		{
			if (sClassList[i].mSubject != "MATH")
			{
				properData = false;
			}
		}
	}
	for (int i = 0; i <= classNumber; i++)
	{
		if (sClassList[i].mEnrollment > sClassList[i].mCapacity)
		{
			properData = false;
		}
	}
	return properData;
}
