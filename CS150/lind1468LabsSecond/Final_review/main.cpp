#include <iostream>
using namespace std;

int computeEven (int numbersArray[], int howMany);
bool bIsPrime (int number);
int computePrimes (int numberArray[], int howMany);
void insert (int numbersArray[], int howMany, int &data);

int number;

int main ()
{
	
	int numberArray[] = {2, 6, 7, 8, 9, 12, 100, 1001, 19};
	int countValues = 9;
	int data;

	cout << "Enter any integer: ";
	cin >> number;
	bool Prime = bIsPrime (number);

	cout << "Number of Primes = " << computePrimes (numberArray, countValues) 
			 << endl;

	return EXIT_SUCCESS;
}
int computeEven (int numbersArray[], int howMany)
{
	int computeEvens = 0;
	for (int i = 0; i < howMany; ++i)
	{
		if (numbersArray[i] % 2 == 0)
		{
			++computeEvens;
		}
	}
	cout << "Number of Evens: " << computeEvens << endl;
	return computeEvens;
}
bool bIsPrime (int number)
{
	for(int i = 2; i < number; ++i)
	{
		if(number % i == 0 )
		{
		return 0;
		}
	}
	return 1;
}
int computePrimes (int numberArray[], int howMany)
{
	int countPrime = 0;

	for(int i = 0; i < howMany; ++i)
	{
		if(true == bIsPrime(numberArray[i]))
		{
			++countPrime;
		}
	}
	return countPrime;
}
void insert (int numbersArray[], int howMany, int &data)
{
	int insertEnd = howMany + 1;

	cout << "Enter a new integer value: ";
	cin >> data;
	numbersArray[insertEnd] = data;

	for (int i = 0; i <= howMany; ++i)
	{
		cout << numbersArray[howMany];
		if (i == howMany)
		{
			howMany = insertEnd;
		}
		if (howMany == insertEnd)
		{
			cout << numbersArray[howMany];
		}
	}

	
}