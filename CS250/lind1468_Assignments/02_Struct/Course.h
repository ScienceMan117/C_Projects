//*****************************************************************************
// File Name:  Course.h
// Author:	   Aidan Lindsey
// Date:	   2/29/2016
// Class:	   CS250-02
// Assignment: Assignment 02_Structs
// Purpose:	   Create the interface for the struct assignment, creating a   
//			   struct and then writing functions to be implemented	 
//*****************************************************************************
#include <iostream>
#include <string>
#include <istream>
#include <fstream>
using namespace std;
// Creates the struct
struct Class
{
	string mSubject;
	int mNumber;
	int mCapacity;
	int mEnrollment;
};
// creates the interface for the functions
void displayHeading();
void displayChoices();
int userInput(int choice);
int numberClasses(istream &inFile);
void readClass(istream &inFile, Class sClassList[100], int classNumber); 
void printClassInfo(ostream &out, Class sClassList[100], int specificClass);
bool lookForClass(Class sClassList[100], string Prefix, int Number, int classNunmber);
bool improperData(Class sClassList[100], int classNunmber);
void AllClassInfo(ostream &out, Class sClassList[100], int classNumber);
string UserPrefix(ostream &out, istream &in);
int UserNumber(ostream &out, istream &in);
int readSingleClass(Class sClassList[100], string Prefix, int Number, int classNumber);
void addStudent(Class sClassList[100], istream &in, ostream &out, int specificClass);