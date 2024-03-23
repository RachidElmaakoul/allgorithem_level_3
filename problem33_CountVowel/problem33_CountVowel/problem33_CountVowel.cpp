// problem33_CountVowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString() {
    string Text;
    cout << "please enter your string : \n";
    getline(cin, Text);
    return Text;
}

bool isVowel(char letter) {
    letter = tolower(letter);
    return ((letter == 'i') || (letter == 'a') || (letter == 'e') || (letter == 'u') || (letter == 'o'));
}
short CountVowel(string Text) {

    short counter = 0;
    for (short i = 0; i < Text.length(); i++)
    {
        if (isVowel(Text[i]))
            counter++;
    }
    return counter;
}

int main()
{
    string Text = ReadString();

    cout << "\n Number of Vowel is :  " << CountVowel(Text) << endl;



    system("pause>0");
}

