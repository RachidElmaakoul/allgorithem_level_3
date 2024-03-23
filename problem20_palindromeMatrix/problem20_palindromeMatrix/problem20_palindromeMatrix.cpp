#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			printf(" %0*d    ", 2, Matrix[i][j]);
			//cout << setw(2) << Matrix[i][j] << "    ";
		}
		cout << endl;
	}
}
bool checkIsPalindrome(int Matrix[3][3],short Rows , short cols) {
	int number = Matrix[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][cols-1-j])
						return false;
		}
	}
	return true;
}


int main()
{

	int  Matrix2[3][3] = {{3,8,3},{3,5,2},{1,9,1}};
	cout << "Matrix 1 : \n";

	PrintMatrix(Matrix2, 3, 3);
	if (checkIsPalindrome(Matrix2, 3, 3))
	{
		cout << "\nYes , it is palindrom matrix\n";
	}
	else {
		cout << "No , it is not palindrom Matrix\n";
	}
	system("pause>0");
	return 0;
}

