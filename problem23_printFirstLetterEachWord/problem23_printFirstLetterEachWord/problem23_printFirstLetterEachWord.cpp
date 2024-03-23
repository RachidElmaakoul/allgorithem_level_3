// problem23_printFirstLetterEachWord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string ReadText() {
	string St1;
	cout << "\nplease enter your string\n";
	getline(cin, St1);
	return St1;
}

void PrintFirstLetterEachWord(string ST1) {
	bool isFirstLetter = true;
	for (short i = 0; i < ST1.length(); i++)
	{
		if (ST1[i] != ' ' && isFirstLetter) {
			cout << ST1[i] << endl;
		}
		isFirstLetter = (ST1[i] == ' ' ? true : false);
	}

}

int main()
{

	PrintFirstLetterEachWord(ReadText());

	return 0;
}

