// problem27_invert_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string ReadCharacter() {
    string Text;
    cout << "please enter character : \n";
    getline(cin, Text);
    return Text;
}



int CountSmallLetterCase(string Text) {
    int SmallNumber = 0;
    for (short i = 0; i < Text.length(); i++)
    {
      if(islower(Text[i]))
        SmallNumber++;
    }
    return SmallNumber;
}
int CountCapitalLetterCase(string Text) {
    int CapitalNumber = 0;
    for (short i = 0; i < Text.length(); i++)
    {
        if (isupper(Text[i]))
        CapitalNumber++;
    }
    return CapitalNumber;
}

// method 2
enum enWhatToCount{CapitalLetters = 1,SmallLetters = 2,All = 3};
short CountLetters(string text, enWhatToCount WhatToCount = enWhatToCount::All) {
    if (WhatToCount == enWhatToCount::All)
    {
        return text.length();
    }
    short counter = 0; 


    for (short i = 0; i < text.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(text[i]))
             counter++;
         if (WhatToCount == enWhatToCount::SmallLetters && islower(text[i]))
             counter++;
    }
    return counter;
}
int main()
{
    string Text = ReadCharacter();
    int CapitalNumber = CountCapitalLetterCase(Text);
    int  SmallNumber = CountSmallLetterCase(Text);



    cout << "\nstring Length         = ";
    cout << Text.length() << endl;
    cout << "Capital letters count = ";
    cout << CapitalNumber << endl;
    cout << "Small letters count   = " << SmallNumber << endl;



    cout << "\n\nmethod 2 \n\n";
    cout << "string length = " << CountLetters(Text)<< endl;
    cout << "Capital Letters Count = " << CountLetters(Text, enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letters Count = " << CountLetters(Text, enWhatToCount::SmallLetters) << endl;

    return 0;
}
