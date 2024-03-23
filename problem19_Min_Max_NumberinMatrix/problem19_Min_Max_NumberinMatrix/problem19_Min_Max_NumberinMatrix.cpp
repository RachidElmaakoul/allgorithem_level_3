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

int GetMin_NumberInMatrix(int Matrix[3][3],short Rows, short cols) {
	short Min = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			if (Matrix[i][j] < Min)
			{
				Min = Matrix[i][j];
			}
		}
	}
	return Min;
}
int GetMax_NumberInMatrix(int Matrix[3][3], short Rows, short cols) {
	short Max = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			if (Matrix[i][j] > Max)
			{
				Max = Matrix[i][j];
			}
		}
	}
	return Max;
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3], Matrix2[3][3];

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << endl;

	cout << " Min number in Matrix is : ";
	cout << GetMin_NumberInMatrix(Matrix, 3, 3) << endl;
	cout << endl;
	cout << " Max number in Matrix is : ";
	cout << GetMax_NumberInMatrix(Matrix, 3, 3) << endl;


	system("pause>0");
	return 0;
}

