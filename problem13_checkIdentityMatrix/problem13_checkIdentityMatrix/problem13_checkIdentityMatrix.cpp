#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int randomNumber(short from, short to) {
	int random = rand() % (to - from + 1) + from;
	return random;
}
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			Matrix[i][j] = randomNumber(0, 9);
		}
	}
}
void PrintMatrix(int Matrix[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			printf(" %0*d    ", 1, Matrix[i][j]);
			//cout << setw(2) << Matrix[i][j] << "    ";
		}
		cout << endl;
	}
}

bool getDiagonaL(int Matrix[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		if (Matrix[i][i] != 1)
			return false;
	}
	return true;
}
bool IsIdentityMarix(int Matrix[3][3], short Rows, short cols) {
	//check Diagonal elements are 1 and rest elements are 0
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			//check for diagonals element
			if (i == j && Matrix[i][j] != 1) 
				return false;
			//check for rest elements
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int Matrix2[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
	// using random number 
	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	if (IsIdentityMarix(Matrix, 3, 3))      
		cout << "\nYES: Matrix is identity.";
	else      
		cout << "\nNo: Matrix is NOT identity.";

	cout << endl;
	// using static array
cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2, 3, 3);
	if (IsIdentityMarix(Matrix2, 3, 3))
		cout << "\nYES: Matrix is identity.";
	else
		cout << "\nNo: Matrix is NOT identity.";
	

	

	system("pause>0");
	return 0;
}

