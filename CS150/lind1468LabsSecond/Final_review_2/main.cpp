#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>

using namespace std;
void computePi (double numTerms);

int main ()
{
	int numTerms = 0;
	computePi(numTerms);
	return EXIT_SUCCESS;
}
void Pi (double numTerms)
{
	double pi = 0;
	double steps;
  cout << "Number of terms = ";
  cin >> numTerms;
  cout << endl;
  cout << "Display Pi after every how many steps? ";
  cin >> steps;
  cout << endl;
 
  for (double count = 1; count <= numTerms; count++)
   {
    if (count % 2 == 0) 
      pi = pi + (1.0 / (2.0 * count - 1));
    else 
      pi = pi - (1.0 / (2.0 * count - 1));
   }
 
  pi=pi*4;

	cout << "Pi = " << computePi(numTerms) << endl;
}