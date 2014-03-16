#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
#include <cctype>
#include "Hash.h"

using namespace std;

const int N = 7;

void ReadFile(string fName, string arr[])
{
	fstream f;
	f.open(fName, ios::in);
	int i = 0;
	while(true)
	{
		getline(f, arr[i], '\n');
		if(f.fail())
		{
			break;
		}
		i++;
	}
	f.close();
}

// function that returns the total ascii of a string
int GetASCII(string str)
{
	int total = 0; int length = str.length();
	for(int i = 0; i < length; i++)
	{
		int x = int(str[i]);
		total += x;
	}
	return total;
}

int main()
{
	// display time and date
	time_t u;
	time(&u);
	cout << ctime(&u) << endl;

	Hash<N> HashObj;  string namesInArray[50] = {};
	int total[50] = {}; string nameToSearch;
	int asciiOfNameToSearch; char ans;
	
	// read the text file
	ReadFile("data.txt", namesInArray);

	// iterate through all names 
	for(int i = 0; i < 50; i++)
	{
		// get all ascii values into array of totals
		total[i] = GetASCII(namesInArray[i]);

		// pass total ascii values into hash function
		HashObj.Insert(total[i]);
	}

	// output list of names and the total ascii values
	for(int i = 0; i < 50; i++)
	{
		cout << left << setfill(' ') << setw(20) << namesInArray[i];
		cout << right << setw(8) << total[i] << endl;
	}

	// output the hash list/table
	cout << endl << endl << endl;
	HashObj.DisplayTable();
	cout << endl << endl << endl;

	// loop for search inquiries
	do 
	{
		cout << "Search for: ";
		getline(cin, nameToSearch, '\n');
		asciiOfNameToSearch = GetASCII(nameToSearch);

		HashObj.Search(nameToSearch, asciiOfNameToSearch);

		cout << "Search another name: " << endl;
		cin >> ans; cin.ignore(); ans = tolower(ans); cout << endl;
	} while(ans == 'y');

	// terminating
	system("Pause");
	return 0;
}