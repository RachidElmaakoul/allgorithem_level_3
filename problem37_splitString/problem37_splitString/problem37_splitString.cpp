// problem33_CountVowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string ReadString() {
    string Text;
    cout << "please enter your string : \n";
    getline(cin, Text);
    return Text;
}


void PrintEachWord(string s1  ) {
    vector <string> eachWord;
    string delim = " ";// delimiter 
    int token = 0;
    string word; // defind a string variable 
    short pos = 0;
    // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, pos);
        if (word != "")
        {
            eachWord.push_back(word);
            token++;
        }
        s1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (s1 != "")
    {
        //cout << s1 << endl; //it print last word of the string
        eachWord.push_back(s1);
        token++;
    }

    cout << "all token : " << token << endl;
    for (string word : eachWord) {
        cout << word << endl;
    }
}


//method abo-hadhoud

 vector <string> splitString(string s1 , string delim ) {
     vector <string> SplitString;
    string word; // defind a string variable 
    short pos = 0;
    // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, pos);
        if (word != "")
        {
            SplitString.push_back(word);
        }
        s1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (s1 != "")
    {
        //cout << s1 << endl; //it print last word of the string
        SplitString.push_back(s1);
    }
    return SplitString;
}

int main()
{
    string Text = ReadString();
    PrintEachWord(Text );




    //method abo-hadhoud
    vector <string> vString;
    vString = splitString(Text, " ");

    cout << "\n Tokens : " << vString.size() << endl;

    for (string &word : vString) {
        cout << word << endl;
    }

    cout << endl;
    system("pause>0");
}

