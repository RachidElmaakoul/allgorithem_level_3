// problem26_Lower-Upper_text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string readText() {
    string Text;
    cout << "please enter your text : \n";
    getline(cin, Text);
    return Text;
}

string  UpperAllstring(string text) {
    for (short i = 0; i < text.length(); i++)
    {
text[i] = toupper(text[i]);
    }
    return text;
}
string LowerAllstring(string text) {
    for (short i = 0; i < text.length(); i++)
    {
text[i] = tolower(text[i]);
    }
    return text;
}

int main()
{

    string text = readText();
    cout << endl;
    cout << "\nstring after upper :\n";
  text =  UpperAllstring(text);
  cout << text <<endl;

    cout << "\n\nstring after lower : \n";
    text = LowerAllstring(text);
    cout << text << endl;






    return 0;
}

