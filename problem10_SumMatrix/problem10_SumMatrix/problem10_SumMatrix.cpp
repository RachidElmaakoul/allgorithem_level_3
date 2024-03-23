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
			Matrix[i][j] = randomNumber(1, 10);
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

int SumAllNumbersInMatrix(int Matrix[3][3],short Rows, short cols ) {
	int SumAllNumberInMatrix = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			SumAllNumberInMatrix += Matrix[i][j];
		}
	}

	return SumAllNumberInMatrix;
}
int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	cout << " Matrix : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << endl;
	cout << "Sum of Matrix is " << SumAllNumbersInMatrix(Matrix, 3, 3) << endl;
	return 0;
}

