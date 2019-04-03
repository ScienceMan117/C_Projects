#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	// PLACE YOUR CONSTANTS HERE. REMOVE THIS COMMENT.

	// PLACE YOUR VARIABLES HERE. REMOVE THIS COMMENT.


	cout << fixed << setprecision(2);

	cout << setw(21) << " " <<  "**************************" << endl;
	cout << setw(21) << " " <<  "*        Rainfall        *" << endl;
	cout << setw(21) << " " <<  "**************************" << endl;
	cout << endl;

	cout << setw(6) << "Week" << setw(15) << "Days in Week" 
		   << setw(26) << "Weekly Precipitation" 
		   << setw(26) << "Average Precipitation" << endl;
	cout << setfill('-') << setw(73) << "";
	cout << setfill(' ') << endl;;

	// WRITE THE REST OF YOUR CODE HERE. REMOVE THIS COMMENT.


	return EXIT_SUCCESS;
}