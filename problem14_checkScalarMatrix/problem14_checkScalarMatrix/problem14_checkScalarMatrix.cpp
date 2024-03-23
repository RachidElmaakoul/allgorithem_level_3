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
bool IsScalarMarix(int Matrix[3][3], short Rows, short cols) {
	int FirstDiagElemement = Matrix[0][0];
	//check Diagonal elements are 1 and rest elements are 0
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			//check for diagonals element
			if (i == j && Matrix[i][j] != FirstDiagElemement)
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
	int Matrix2[3][3] = { {9,0,0},{0,7,0},{0,0,1} };
	int Matrix3[3][3] = { {5,0,0},{0,5,0},{0,0,5} };
	// using random number 
	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	if (IsScalarMarix(Matrix, 3, 3))
		cout << "\nYES: Matrix is Scalar.";
	else
		cout << "\nNo: Matrix is NOT Scalar.";

	cout << endl;
	// using static array
	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2, 3, 3);
	if (IsScalarMarix(Matrix2, 3, 3))
		cout << "\nYES: Matrix is Scalar.";
	else
		cout << "\nNo: Matrix is NOT Scalar.";

	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix3, 3, 3);
	if (IsScalarMarix(Matrix3, 3, 3))
		cout << "\nYES: Matrix is Scalar.";
	else
		cout << "\nNo: Matrix is NOT Scalar.";



	system("pause>0");
	return 0;
}

