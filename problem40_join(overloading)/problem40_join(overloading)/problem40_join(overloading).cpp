

#include <iostream>
#include <string>
#include <vector>
using namespace std;


string Joinstring(vector <string> vString, string delm) {
	string s1 = "";
	for (string& s : vString) {
		s1 = s1 + s + delm;
	}
	return s1.substr(0, s1.length() - delm.length());
}


string Joinstring(string arr[], string delm, short length) {
	string s1 = "";
	for (short i = 0; i < length ; i++) {
		s1 =  s1 + arr[i] + delm;
	}
	return s1.substr(0, s1.length() - delm.length());
}


int main()
{ 
	vector <string> Vstring{ "rachid","el","maakoul"};
	string arr[] = { "rachid","el","maakoul" };
	cout << "\nvector after join\n";
	cout << Joinstring(Vstring, "-");

	cout << "\n\narray after join\n";
	cout << Joinstring(arr, "-" , 3);

	cout << endl;

	return 0;
}

