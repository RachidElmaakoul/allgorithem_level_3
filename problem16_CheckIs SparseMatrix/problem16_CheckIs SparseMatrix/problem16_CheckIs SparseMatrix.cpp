#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//sparce mains check if repeated number 0 greater than other number;
int randomNumber(short from, short to) {
	int random = rand() % (to - from + 1) + from;
	return random;
}
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			Matrix[i][j] = randomNumber(0, 1);
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
int ReadNumber() {
	int Number;
	cout << "please enter the number to count in Matrix ? \n";
	cin >> Number;
	return Number;
}

bool CheckIsSparceMatrix(int Matrix[3][3], short Rows, short cols) {
	short CountZero = 0;
	short CountOtherNumber = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (Matrix[i][j] == 0)
				CountZero++;
			else
				CountOtherNumber++;
		}
	}
	if (CountZero > CountOtherNumber)
	{
		return true;
	}
	return false;
}

//Method abo-hadhoud
short CountNumberInMatrix(int Matrix[3][3], short Number, short Rows, short cols) {
	short CountNumber = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (Matrix[i][j] == Number)
				CountNumber++;
		}
	}
	return CountNumber;
}

bool IsSparceMatrix(int Matrix[3][3], short Number, short Rows, short cols) {
	short MatrixSize = Rows * cols;
	return (CountNumberInMatrix(Matrix, Number, Rows, cols) > ceil((float)MatrixSize / 2));
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);


	if (CheckIsSparceMatrix(Matrix, 3, 3))
		cout << "\nYes ,  it is sparce .\n";
	else
		cout << "\nNo , it is Not  Sparce . \n";


	cout << "Matrix 2 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);
	
if (IsSparceMatrix(Matrix,0, 3, 3))
		cout << "\nYes ,  it is sparce .\n";
	else
		cout << "\nNo , it is Not  Sparce . \n";

	
	





	system("pause>0");
	return 0;
}

