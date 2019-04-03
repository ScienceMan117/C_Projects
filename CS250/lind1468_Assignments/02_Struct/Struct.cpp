//*****************************************************************************
// File Name:  Struct.cpp
// Author:	   Aidan Lindsey
// Date:	   2/29/2016
// Class:	   CS250-02
// Assignment: Assignment 02_Structs
// Purpose:	   Makes an struct object, that calls function in Course.cpp to  
//			   allow the user to choose to Display all classes, display a 
//             single course, add a student to a class or quit the program
//*****************************************************************************
#include <iostream>
#include "Course.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
	// create an object array of the struct
	Class ClassList[100];
	// create an enum of options available
	enum ClassChoice{ ONE = 1, TWO, THREE, FOUR };
	// list all variables
	const int QUIT = 4;
	int classNumber = 0;
	int choice = 0;
	ifstream inFile;
	string Prefix;
	int number = 0;
	bool classExists = false;
	bool properData = true;
	int specificClass = 0;
	// open file to count number of rows
	inFile.open("Course.txt");
	classNumber = numberClasses(inFile);
	// close file to be used again
	inFile.close();
	// open file again to be used for the rest of the program
	inFile.open("Course.txt");
	// Display heading information, reads the struct class and makes sure the data
	// in the file is valid
	displayHeading();
	readClass(inFile, ClassList, classNumber);
	properData = improperData(ClassList, classNumber);
	// if the information is invalid let the user know and turn program off
	if (properData == false)
	{
		cout << "Error: Improper data in File. Please fix file to Continue.";
		cout << endl;
		inFile.close();
		return EXIT_SUCCESS;
	}
	// Allow the user to input an option
	displayChoices();
	choice = userInput(choice);
	cout << endl;
	// Allow the user to continue to make options until they decide to press 4 to quit
	while (choice != QUIT)
	{
		// if the user doesnt input a 1, 2, 3 or 4 force the user to input a proper 
		// value
		while (choice != ONE && choice != TWO && choice != THREE && choice != FOUR)
		{
			displayChoices();
			choice = userInput(choice);
			cout << endl;
		}
		// if the user inputs option 1 then the program will output all the classes
		if (choice == ONE)
		{
			AllClassInfo(cout, ClassList, classNumber);
		}
		// if the user inputs option 2 then the program will ask the user to give a 
		// prefix and a number and then the program will search through the 
		// sClassList[100] to find the user input
		if (choice == TWO)
		{
			Prefix = UserPrefix(cout, cin);
			number = UserNumber(cout, cin);
			classExists = lookForClass(ClassList, Prefix, number, classNumber);
			// if the user input is in sClassList[100] then the specific class will
			// be outputed to the screen
			if (classExists == true)
			{
				specificClass = readSingleClass(ClassList, Prefix, number, classNumber);
				printClassInfo(cout, ClassList, specificClass);
			}
		}
		// // if the user inputs option 3 then the program will ask the user to give a 
		// prefix and a number and then the program will search through the 
		// sClassList[100] to find the user input
		if (choice == THREE)
		{
			Prefix = UserPrefix(cout, cin);
			number = UserNumber(cout, cin);
			classExists = lookForClass(ClassList, Prefix, number, classNumber);
			// if the user input is in sClassList[100] then a student will be added to
			// the class unless the class is full
			if (classExists == true)
			{
				specificClass = readSingleClass(ClassList, Prefix, number, classNumber);
				addStudent(ClassList, cin, cout, specificClass);
			}
		}
		displayChoices();
		choice = userInput(choice);
		cout << endl;
	}
	// close the file 
	inFile.close();
	// end program
	return EXIT_SUCCESS;
}