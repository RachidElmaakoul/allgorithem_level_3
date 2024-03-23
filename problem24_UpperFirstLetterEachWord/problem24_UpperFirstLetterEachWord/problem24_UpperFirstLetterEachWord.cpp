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

void upperFirstLetterEachWord(string ST1) {
	string text = " ";
	bool isFirstLetter = true;
	for (short i = 0; i < ST1.length(); i++)
	{
		if (ST1[i] != ' ' && isFirstLetter) {
			cout << (char)toupper(ST1[i]);
		}
		else
		{
			cout << ST1[i];
		}
	isFirstLetter = (ST1[i] == ' ' ? true : false);
	}
}

// method abo-hadhoud
string UpperFirstLetterEachWord(string ST1) {
	bool isFirstLetter = true;
	for (short i = 0; i < ST1.length(); i++)
	{
		if (ST1[i] != ' ' && isFirstLetter) {
			ST1[i] = toupper(ST1[i]);
		}
		isFirstLetter = (ST1[i] == ' ' ? true : false);
	}
	return ST1;
}

int main()
{
	string s1 = ReadText();
	cout << "\n\n the text after convert\n";
	 upperFirstLetterEachWord(s1);

	 cout << "\n\n the text after convert\n";
	s1 = UpperFirstLetterEachWord(s1);
	cout << s1 << endl;;
	return 0;
}

