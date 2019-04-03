#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;
	char dnaArray[100];
	inFile.open("Text.txt");

	if (!inFile)
	{
		cout << "Error" << endl;
		return EXIT_SUCCESS;
	}

	char base = inFile.get();
	int i = 0;
	while (('\n' != base && EOF != base) && i < 100)
	{
		dnaArray[i] = base;
		i++;
		base = inFile.get();
	}
	dnaArray[i] = '\0';
	inFile.close();
	return EXIT_SUCCESS;
}