
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

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

//method abo-hadhoud
string ReverseWordToString(string s1) {
    vector <string> vwordToString;
    string s2 = "";
    
    vwordToString = reverseWords(s1, " ");

    vector <string>::iterator iter = vwordToString.end();
    while (iter != vwordToString.begin())
    {
        iter--;
        s2 += *iter + " ";
    }
    s2 = s2.substr(0, s2.length() - 1);//remove last space;
    return s2;

}
int main()
{
    vector <string> vstring;
    string st;
    cout << "please enter your string : ";
    getline(cin,st);

    vstring =  reverseWords(st , " ");
    for (short i = vstring.size() - 1; i >= 0; i--) {
        cout << vstring.at(i) << " ";
   }
    cout << endl;
    //method abo-hadhoud
    cout << ReverseWordToString( st);

    return 0;
}

