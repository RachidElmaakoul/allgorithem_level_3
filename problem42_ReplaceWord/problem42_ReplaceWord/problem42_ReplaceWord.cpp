
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
string readString() {
    string st;
      cout << "please enter your string : ";
    getline(cin, st);
    return st;
}

vector <string> reverseWords(string s1, string delim) {
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

string ReplaceWithMatchCase( string StringToReplace,string SreplaceTo , vector <string> vstring) {
    string s1 ="";
    for (string a : vstring) {
        if (a == StringToReplace)
            a = SreplaceTo;
        s1 = s1 + a + " ";
    }
    s1 = s1.substr(0, s1.length() - 1);
    return s1;
}
string toLower(string word) {
    for (short i = 0; i < word.length(); i++)
    {
       word[i] = tolower(word[i]);
    }
    return word;
}
string ReplaceWithDontMatchCase( string StringToReplace,string SreplaceTo , vector <string> vstring) {
    string s1 ="";
    for (string &a : vstring) {
     
        if (toLower(a) == StringToReplace)
        {
            a = SreplaceTo;
        }
        s1 = s1 + a + " ";
    }
    s1 = s1.substr(0, s1.length() - 1);
    return s1;
}

//method abo-hadhoud
string JoinString(vector <string> vString , string delem) {
    string s1 = "";
    for (string & word : vString )
    {
        s1 += word + delem;
    }
    s1.substr(0, s1.length() - delem.length());
    return s1;
}
string ToLower(string s1) {
    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
    }
    return s1;
}

string ReplaceWordInString(string s1,string StringToReplace , string SreplaceTo, bool MatchCase = true) {
    vector <string> vString = reverseWords(s1, " ");
    for (string &s : vString) {

        if (MatchCase)
        {
            if (s == StringToReplace)
                s = SreplaceTo;
        }
        else
        {
            if (ToLower(s) == ToLower(StringToReplace))
                s = SreplaceTo;
        }
    }
    return JoinString(vString, " ");
}

int main()
{
    vector <string> vstring;
    string st = readString();
    string    StringToReplace = "morocco";
    string  SreplaceTo = "USA";

    vstring = reverseWords(st, " ");

    cout << "\nreplace word with match case : \n";
    cout << ReplaceWithMatchCase(StringToReplace, SreplaceTo, vstring) << endl;

   cout << "\nreplace word with dont match case : \n";
   cout  << ReplaceWithDontMatchCase(StringToReplace, SreplaceTo, vstring);

   cout << "\n\n method abo-hadhoud \n\n";

    cout << "\nreplace word with match case : \n";
    cout << ReplaceWordInString(st,StringToReplace, SreplaceTo) << endl;

   cout << "\nreplace word with dont match case : \n";
   cout  << ReplaceWordInString(st,StringToReplace, SreplaceTo, false);

    system("\n\n\n\npause>0");
    return 0;
}

