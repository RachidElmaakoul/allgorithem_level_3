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
			Matrix[i][j] = randomNumber(1, 99);
		}
	}
}
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
int ReadNumber() {
	int Number;
	cout << "please enter the number to look for in Matrix ? \n";
	cin >> Number;
	return Number;
}

bool IsExistsNumberInMatrix(int Matrix[3][3], short Number, short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);



	if (IsExistsNumberInMatrix(Matrix, ReadNumber(), 3, 3))
		cout << "Yes , it is there .\n";
	else
		cout << "No it is Not There . \n";




	system("pause>0");
	return 0;
}

