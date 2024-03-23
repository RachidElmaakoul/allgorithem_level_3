
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadCharacter() {
    char letter;
    cout << "please enter a Character : ";
    cin >> letter;
    return letter;
}
bool IsVowel(char letter) {
    char AllVowel[5] = { 'a','e','i','o','u' };
    for (short i = 0; i < 5; i++)
    {
        if (AllVowel[i] == tolower(letter))
            return true;
    }
    return false;
}

//method abu-hadhoud
bool isVowel(char letter) {
    letter = tolower(letter);
    return (letter == 'i' || letter == 'a' || letter == 'e' || letter == 'u' || letter == 'o');
}
int main()
{
    char Letter = ReadCharacter();


    if (IsVowel(Letter))
        cout << "\nYes, \'" << Letter << "\' is vowel .\n";
    else
        cout << "\nNo, \'" << Letter << "\' is Not vowel .\n"; 
    

    // method abu-hadoud
    cout << endl << endl;
    if (isVowel(Letter))
        cout << "\nYes, \'" << Letter << "\' is vowel .\n";
    else
        cout << "\nNo, \'" << Letter << "\' is Not vowel .\n";



    return 0;
}

