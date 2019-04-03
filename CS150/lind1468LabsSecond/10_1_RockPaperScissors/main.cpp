//******************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				10/29/13
// Class:				CS150-01
// Assignment:	Functions and Random Numbers
// Purpose:			Use functions to create a game of rock, paper, scissors.
//******************************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayMenu ();
void printTitle (string title);
int getComputerSelection ();
int getUserSelection ();
void displaySelection (string player, int selection);
int determineWinner (int playerOneSelection, int playerTwoSelection);
void displayWinnerMessage (int userSelection, int computerSelection);

const int QUIT = 4;
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int WIN = 1;
const int LOSE = 2;
const int DRAW = 3;

/******************************************************************************
 Function:     main

 Description:  Plays the game ROCK PAPER SCISSORS between the user and the
							 computer

 Parameters:   None

 Returned:     Exit Status
******************************************************************************/
int main ()
{
	int userSelection, computerSelection;
	
	// seed random number generator
	srand (static_cast<unsigned> (time (static_cast<time_t *>(NULL))));

	printTitle ("Rock - Paper - Scissors");

	userSelection = getUserSelection ();

	if (QUIT != userSelection)
	{
		
		computerSelection = getComputerSelection ();

		cout << endl;

		displaySelection ("User" , userSelection);
		displaySelection ("Computer", computerSelection);
	
		cout << endl;

		displayWinnerMessage (userSelection, computerSelection);

		cout << endl;
	}
	return EXIT_SUCCESS;
}


/******************************************************************************
 Function:     printTitle

 Description:  Displays a title to the screen in the form:

							 **************************
							 * title
							 **************************

 Parameters:   title - the title to be displayed to the screen

 Returned:     None
******************************************************************************/
void printTitle (string title)
{
	cout << setw(21) << " " <<  "**************************" << endl;
	cout << setw(21) << " " <<  "* " << title << endl;
	cout << setw(21) << " " <<  "**************************" << endl;
	cout << endl;
}

/******************************************************************************
 Function:     displayMenu

 Description:  Displays a menu to the screen in the form:

							 Select one of the following:

							 1. Rock
							 2. Paper
							 3. Scissors
							 4. Quit

							 Selection:

 Parameters:   None

 Returned:     None
******************************************************************************/
void displayMenu ()
{
	cout << "Select one of the following: \n\n";
	cout << "1. Rock\n" << "2. Paper\n" << "3. Scissors\n"
			 << "4. Quit\n" << endl;
	cout << "Selection: ";
}

/******************************************************************************
 Function:     getComputerSelection

 Description:  Randomly generates a number between 1 and 3 inclusive

 Parameters:   None

 Returned:     The randomly generated number
******************************************************************************/
int getComputerSelection ()
{
	int computerSelection = rand () % SCISSORS + ROCK;

	return computerSelection;
}

/******************************************************************************
 Function:     getUserSelection

 Description:  Displays the menu by calling displayMenu, then reads in the
							 user's selection. It will continue reading in the selection
							 until the user enters a valid selection

 Parameters:   None

 Returned:     The user's selection of ROCK, PAPER, or SCISSORS
******************************************************************************/
int getUserSelection ()
{
	int userSelection;

	do
	{
		displayMenu ();
		cin >> userSelection;
		cout << endl;
	} while (userSelection < ROCK || userSelection > SCISSORS);

	return userSelection;
}

/******************************************************************************
 Function:     displaySelection

 Description:  Prints a message to the screen displaying the player's
							 selection in the form:

							 "player" selected "selection"

 Parameters:   player    - the player. Either "User" or "Computer"
							 selection - the player's selection. 

 Returned:     None
******************************************************************************/
void displaySelection (string player, int selection)
{
	cout << player << " Selected ";

	if (selection == ROCK)
	{
		cout << "ROCK" << endl;
	}

	if (selection == PAPER)
	{
		cout << "PAPER" << endl;
	}
	
	if ( selection == SCISSORS)
	{
		cout << "SCISSORS" << endl;
	}
}

/******************************************************************************
 Function:     determineWinner

 Description:  Determines whether the user or computer have one the game

 Parameters:   playerOneSelection - ROCK, PAPER, or, SCISSORS
							 playerTwoSelection - ROCK, PAPER, or, SCISSORS 

 Returned:     DRAW if the players make the same selection
							 WIN if player one beats player two
							 LOSE if player two beats player one
******************************************************************************/
int determineWinner (int playerOneSelection, int playerTwoSelection)
{
	int winCondition;

	if (playerOneSelection == playerTwoSelection)
	{
		winCondition = DRAW;
	}

	if (ROCK == playerOneSelection && playerTwoSelection == SCISSORS)
	{
		winCondition = WIN;
	}

	if (ROCK == playerOneSelection && playerTwoSelection == PAPER)
	{
		winCondition = LOSE;
	}

	if (SCISSORS == playerOneSelection && playerTwoSelection == ROCK)
	{
		winCondition = LOSE;
	}

	if (SCISSORS == playerOneSelection && playerTwoSelection == PAPER)
	{
		winCondition = WIN;
	}

	if (PAPER == playerOneSelection && playerTwoSelection == SCISSORS)
	{
		winCondition = LOSE;
	}
	
	if (PAPER == playerOneSelection && playerTwoSelection == ROCK)
	{
		winCondition = WIN;
	}

	return winCondition;
}

/******************************************************************************
 Function:     displayWinnerMessage

 Description:  Display one of three messages depending on the outcome of the 
							 game. The possible messages are:

							 Congratulations! You Won.
							 Sorry. You lose.
							 It's a draw!

 Parameters:   playerOneSelection - ROCK, PAPER, or, SCISSORS
							 playerTwoSelection - ROCK, PAPER, or, SCISSORS 

 Returned:     None
******************************************************************************/
void displayWinnerMessage (int userSelection, int computerSelection)
{
	int winOutcome = determineWinner (userSelection, computerSelection);

	if (winOutcome == DRAW)
	{
		cout << "It's a Draw!" << endl << endl;
	}

	if (winOutcome == LOSE)
	{
		cout << "Sorry. You lose." << endl << endl;
	}

	if (winOutcome == WIN)
	{
		cout << "Congratulations! You won." << endl << endl;
	}
}