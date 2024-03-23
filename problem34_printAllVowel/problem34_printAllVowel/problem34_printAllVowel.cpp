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

bool IsVowel(char letter) {
    char Vowel[10] = { 'a','A','e','E','i','I','u','U','o','O' };
    for (short i = 0; i < 10; i++)
    {
        if (letter == Vowel[i])
            return true;
    }
    return false;
}

void PrintAllVowel(string Text) {
    for (short i = 0; i < Text.length(); i++)
    {
        if (IsVowel(Text[i]))
            cout << Text[i] << "  ";
    }
}
//method abu-hadoud
bool isvowel(char letter) {
    letter = tolower(letter);
    return ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'u') || (letter == 'o'));

}
void PrintAllVowel1(string Text) {
 cout << "\n\n Vowels in string are : ";
    for (short i = 0; i < Text.length(); i++)
    {
        if (isvowel(Text[i]))
            cout << Text[i] << "  ";
    }
}

int main()
{
    string Text = ReadString();
    cout << "All Vowels are : ";
    PrintAllVowel(Text); 
    
    
   
    PrintAllVowel1(Text);


    cout << endl;
    system("pause>0");
}

