// problem27_invert_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char ReadCharacter() {
    char Character;
    cout << "please enter character : \n";
    cin >> Character;
    return Character;
}

char InvertCharacter(char Char) {
    if (islower(Char))
      return  toupper(Char);
    else
      return tolower(Char);
}
//method abu-hadhoud
char InvertLetterCase(char Ch1) {
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

int main()
{
    char Ch1= ReadCharacter();
 cout << "\nChar after inverting case:\n";
cout <<     InvertCharacter(Ch1);

cout << "\nChar after inverting case:\n";
Ch1 = InvertCharacter(Ch1);
cout << Ch1 << endl;



    return 0;
}
