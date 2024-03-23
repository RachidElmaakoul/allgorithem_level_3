// problem38_trimLeftAndRightandAll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string ReadString() {
    string s1;
    cout << "please enter string ?\n";
    getline(cin, s1);
    return s1;
}

string TrimLeft(string s1) {
    for (short i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ' ')
          return  s1.substr(i,s1.length() - 1);
    }
    return "";
}
string TrimRight(string s1) {
    for (short i = s1.length() - 1; i >= 0; --i)
    {
        if (s1[i] != ' ')
          return  s1.substr(0,i + 1);
    }
    return "";
}

string TrimAll(string s1) {
    return TrimRight(TrimLeft(s1));
}
int main()
{
 
    string text = ReadString();

    cout << "normal text : " << text << endl;
    cout << "trim left   : " << TrimLeft(text) << endl;
    cout << "trim right  : " << TrimRight(text) << endl;
    cout << "trim All    : " << TrimAll(text) << endl;
    return 0;
}

