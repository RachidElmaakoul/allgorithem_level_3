
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



//method abu dahdouh
//this is  best 

short PrintEachWord(string s1) {

    string delim = " ";// delimiter 

    string word; // defind a string variable 
    short pos = 0;
    short counter = 0;
    // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, pos);
        if (word != "")
        {
            counter++;
        }
        s1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (s1 != "")
    {
        counter++;
    }
    return counter ;
}

int main()
{
    string Text = ReadString();


    cout << "\nThe number of words in your string is: ";
   cout <<  PrintEachWord(Text);

    cout << endl;
    system("pause>0");
}

