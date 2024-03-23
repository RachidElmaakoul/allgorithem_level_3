// problem30_countLetters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string ReadString() {
    string Text;
    cout << "please enter you string \n";
    getline(cin, Text);
    return Text;
}
char Readcharacter() {
    char Char1;
    cout << "\nplease enter a character :  \n";
    cin >> Char1;
    return Char1;
}

short CountLetter(string Text,char Char1) {
    short counter = 0;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] == Char1)
            counter++;
    }
    return counter;
}

int main()
{
    string Text = ReadString();
    char Char1 = Readcharacter();
   
    cout << "\nLetter \'" << Char1 << "\' count : ";
    cout << CountLetter(Text, Char1) << endl;



    return 0;
}

