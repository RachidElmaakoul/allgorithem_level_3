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
string upperToLower(string Text , char ch) {
    for (short i = 0; i < Text.length(); i++)
    {
        if (isupper(ch))
            Text[i] = toupper(Text[i]);
        else
            Text[i] = tolower(Text[i]);
    }return Text;
}
short countletters(string Text, char ch) {
    short counter = 0;
    for (short i = 0; i < Text.length(); i++)
    {
        if (  Text[i] == tolower(ch) ||   Text[i] == toupper(ch))
            counter++;
    }
    return counter;
}
short CountLetter(string Text, char Char1) {
    short counter = 0;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] == Char1)
            counter++;
    }
    return counter;
}

// Method abu-hadhoud
char invertLetterCase(char letter) {
    return islower(letter) ? toupper(letter) : tolower(letter);
}

short CountOfletter(string Text, char letter, bool MatchCase = true) {

    short counter = 0;
    for (short i = 0; i < Text.length(); i++)
    {
        if (MatchCase)
        {
            if (Text[i] == letter)
                counter++;
        }
        else
        {
            if (tolower(Text[i]) ==  tolower(letter) )
                counter++;
        }
    }
    return counter;
}

int main()
{
    string Text = ReadString();
    char Char1 = Readcharacter();
 /*   string ChangeAllLetter = upperToLower(Text, Char1);
    cout << "\nLetter \'" << Char1 << "\' count : ";
    cout << CountLetter(Text, Char1) << endl;

    cout << "\n\n";

    cout << " letters \'" << (char)toupper(Char1) << "\'  OR  \'" << (char)tolower(Char1) << "\'  count: ";
    cout << CountLetter(ChangeAllLetter, Char1) << endl;


    cout << "\n\n";
    cout << "letters \'" << (char)toupper(Char1) << "\'  OR  \'" << (char)tolower(Char1) << "\'  count: ";
    cout <<  countletters(Text, Char1) << endl;
    
    */
    //method abu-hadhoud
    cout << "\n\n";
    //cout << "\nLetter \'" << Char1 << "\' count : " << CountOfletter(Text, Char1) << endl;
    cout << " letters \'" << Char1 << "\'  OR  \'";
    cout <<invertLetterCase(Char1) << "\'  count: ";
    cout << CountOfletter(Text, Char1,false) << endl;

    return 0;
}

