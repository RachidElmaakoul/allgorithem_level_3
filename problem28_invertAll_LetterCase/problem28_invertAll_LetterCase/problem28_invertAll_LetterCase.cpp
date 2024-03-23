// problem27_invert_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string ReadCharacter() {
    string Text;
    cout << "please enter character : \n";
    getline(cin, Text);
    return Text;
}

string InvertAll_LetterCase(string Text) {
    for (short i = 0; i < Text.length(); i++)
    {
       Text[i] = isupper(Text[i]) ? tolower(Text[i]) : toupper(Text[i]);
    }
    return Text;
}

//method Abu-Hadhoud
char InvertLetterCase(char char1) {
    return isupper(char1) ? tolower(char1) : toupper(char1);
}


string InvertAllStringLetterCase(string Text) {
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = InvertLetterCase(Text[i]);
    }
    return Text;
}

int main()
{
    string Text = ReadCharacter();
  

  cout << "\Text after inverting All case:\n";
    Text = InvertAll_LetterCase(Text);
    cout << Text << endl;


    cout << "\Text after inverting All case:\n";
    Text = InvertAllStringLetterCase(Text);
    cout << Text;

    return 0;
}
