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

// this method it had some issuse 
// if was many space that is effect it
string printEachWordInString(string text) {
    char end = '\n';
    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            text[i] = end;
    }
    return text;
}

//method abu dahdouh
//this is  best 

void PrintEachWord(string s1) {

    string delim = " ";// delimiter 

    string word; // defind a string variable 
    short pos = 0;
  // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, pos);
        if (word != "")
        {
            cout << word << endl;//store the word
        }
        s1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (s1 != "")
    {
        cout << s1 << endl; //it print last word of the string
    }
}

int main()
{
    string Text = ReadString();
 
   cout <<endl << printEachWordInString(Text) << endl;


   PrintEachWord(Text);

    cout << endl;
    system("pause>0");
}

