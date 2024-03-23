// problem39_JoinSting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string readString() {
	string s1;
	cout << "please enter string : ";
	cin >> s1;
	return s1;
}

string Joinstring(vector <string> vString, string delm) {
	string s1 = "";
	for (string& s : vString) {
		s1 = s1 + s + delm;
	}
	return s1.substr(0, s1.length() - delm.length());
}
int main()
{                                                   // if want to add internal string
	vector <string> Vstring{"rachid","el","maakoul",readString() };
	cout << "\nvector after join\n";
	cout << Joinstring(Vstring, "/");
	
	cout << endl;

	return 0;
}

