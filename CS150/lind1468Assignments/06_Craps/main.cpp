//*****************************************************************************
// File Name:	 main.cpp
// Author:		 Aidan Lindsey
// Date:			 11/4/2013
// Class:			 CS150-01
// Assignment: Craps!
// Purpose:		 Use functions and voids to create a game of Craps.
// Hours:		   5 hours.
//*****************************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// List function names.
void drawHeading ();
void drawDieFace (int face); 
int rollDie ();
void drawDiceFace (int face1, int face2);

// List global constant integers.
const int VALUE_BOTTOM = 0;
const int SEVEN_WIN = 7;
const int ELEVEN_WIN = 11;
const int TWO_LOSE = 2;
const int THREE_LOSE = 3;
const int SEVEN_LOSE = 7;
const int TWELVE_LOSE = 12;
const int FACE_ONE = 1;
const int FACE_TWO = 2;
const int FACE_THREE = 3;
const int FACE_FOUR = 4;
const int FACE_FIVE = 5;
const int FACE_SIX = 6;

/******************************************************************************
 Function:     main

 Description:  Plays the game CRAPS

 Parameters:   None

 Returned:     Exit Status
******************************************************************************/
int main ()
{
	// List variables that will run in the int main ().
	int dieRoll1, dieRoll2, point;
	int dieRollTotal = 0;
	int rollCount = 0;
	bool bVal;


	srand (static_cast<unsigned> (time (static_cast<time_t *>(NULL))));
	
	// Have Craps game keep going until conditions are met.
	if (dieRollTotal == VALUE_BOTTOM)
	{
		bVal = true;
	}

	while (bVal == true) 
	{
		dieRoll1 = rollDie ();
		dieRoll2 = rollDie ();

		dieRollTotal = dieRoll1 + dieRoll2;
		drawDiceFace (dieRoll1, dieRoll2);

		if (rollCount == VALUE_BOTTOM)
		{
			point = dieRollTotal;
		}

		if (dieRollTotal == SEVEN_WIN && rollCount == VALUE_BOTTOM)
		{
			cout << "Congratulations! You rolled a 7. You win!" << endl << endl;
			bVal = false;
		}

		else if (dieRollTotal == ELEVEN_WIN && rollCount == VALUE_BOTTOM)
		{
			cout << "Congratulations! You rolled a 11! You win!" << endl << endl;
			bVal = false;
		}

		else if (dieRollTotal == TWO_LOSE && rollCount == VALUE_BOTTOM) 
		{
			cout << "Sorry, you rolled a 2. You crapped out!" << endl << endl;
			bVal = false;
		}

		else if (dieRollTotal == THREE_LOSE && rollCount == VALUE_BOTTOM)
		{
			cout << "Sorry, you rolled a 3. You crapped out!" << endl << endl;
			bVal = false;
		}

		else if (dieRollTotal == TWELVE_LOSE && rollCount == VALUE_BOTTOM)
		{
			cout << "Sorry, you rolled a 12. You crapped out!" << endl << endl;
			bVal = false;
		}
		
		else if (dieRollTotal == SEVEN_LOSE && rollCount > VALUE_BOTTOM)
		{
			cout << "Sorry, you rolled a 7. You crapped out!" << endl << endl;
			bVal = false;
		}
		
		else if (dieRollTotal == point && rollCount > VALUE_BOTTOM)
		{
			cout << "Congratulations! You rolled a " << point << ". You win!" 
					 << endl << endl;
			bVal = false;
		}

		else
		{
		cout << "You must roll a " << point 
				 << " to win. If you a roll a 7, you lose." << endl << endl;
		}

		rollCount++;

		if (bVal != false)
		{
			system("pause");
			system("cls");
		}	
	}
	return EXIT_SUCCESS;
}

/******************************************************************************
 Function:     drawHeading

 Description:  Displays title to the screen in the form:
							 **********************
							 *			 Craps        *
							 **********************

 Parameters:   None

 Returned:     None
******************************************************************************/
void drawHeading ()
{
	cout << "**********************" << endl;
	cout << "*        Craps       *" << endl;
	cout << "**********************" << endl;
	cout << endl;
}

/******************************************************************************
 Function:     drawDieFace

 Description:  Draws the die face that is passed into the paramater as follows:
							 -----
							 |o o|
							 |	 |
							 |o	o|
							 -----

 Parameters:   None

 Returned:     None
******************************************************************************/
void drawDieFace (int face)
{
	if (face == FACE_ONE)
	{
		cout << "-----" << endl;
		cout << "|   |" << endl;
		cout << "| o |" << endl;
		cout << "|   |" << endl;
		cout << "-----" << endl;
	}

	if (face == FACE_TWO) 
	{
		cout << "-----" << endl;
		cout << "|o  |" << endl;
		cout << "|   |" << endl;
		cout << "|  o|" << endl;
		cout << "-----" << endl;
	}

	if (face == FACE_THREE)
	{
		cout << "-----" << endl;
		cout << "|o  |" << endl;
		cout << "| o |" << endl;
		cout << "|  o|" << endl;
		cout << "-----" << endl;
	}

	if (face == FACE_FOUR)
	{
		cout << "-----" << endl;
		cout << "|o o|" << endl;
		cout << "|   |" << endl;
		cout << "|o o|" << endl;
		cout << "-----" << endl;
	}

	if (face == FACE_FIVE)
	{
		cout << "-----" << endl;
		cout << "|o o|" << endl;
		cout << "| o |" << endl;
		cout << "|o o|" << endl;
		cout << "-----" << endl;
	}

	if (face == FACE_SIX)
	{
		cout << "-----" << endl;
		cout << "|o o|" << endl;
		cout << "|o o|" << endl;
		cout << "|o o|" << endl;
		cout << "-----" << endl;
	}
}	

/******************************************************************************
 Function:     rollDie

 Description:  Rolls one random die and returns the roll value.

 Parameters:   dieRoll - random integer between 1 and 6.

 Returned:     One random die roll value.
******************************************************************************/
int rollDie ()
{
	 int dieRoll = rand () % FACE_SIX + FACE_ONE;

	 return dieRoll;
}
/******************************************************************************
 Function:     drawDiceFace

 Description:  Calls drawDieFace twice showing a special output as seen on the 
							 screen as follows:

							 Dice Pair (4, 2)
							 -----
							 |o o|
							 |   |
							 |o o|
							 -----
							 -----
							 |o  |
							 |   |
							 |  o|
							 -----

 Parameters:   face		- random number choosen between 1 and 6.

 Returned:     None
******************************************************************************/
void drawDiceFace (int face1, int face2)
{
	cout << "Dice pair (" << face1 << ", " << face2 << ")" << endl;
	drawDieFace (face1); 
	drawDieFace (face2);
}