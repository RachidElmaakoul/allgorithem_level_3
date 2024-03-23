

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
string RemovePunctuationsFromStrin(string s1) {
	string s2 = "";
	for (short i = 0; i < s1.length(); i++)
	{
		if (!ispunct(s1[i]))
			s2 += s1[i];
	}
	return s2;
}



int main()
{
	string s1 = "rachid, el-maakoul,_-(){}[]/*-+%^&*($#@ i'm from morocco";
	
	cout << " \n the original string is : \n" << s1;
	cout << "\n\n string after remove the punctuations : \n";
	cout << RemovePunctuationsFromStrin(s1) << endl;




	system("pause>0");
	return 0;
}

