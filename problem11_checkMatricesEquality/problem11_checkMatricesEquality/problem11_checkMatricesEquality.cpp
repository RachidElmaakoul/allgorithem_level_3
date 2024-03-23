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
int SumMatrix(int Matrix[3][3], short Rows, short cols) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			Sum += Matrix[i][j];
		}
	}
	return Sum;
}
bool CheckMatrices(int Matrix1[3][3], int Matrix2[3][3],  short Rows, short cols) {
	return (SumMatrix(Matrix1, 3, 3) == SumMatrix(Matrix2, 3, 3));
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3] ;
	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2 \n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);

	
	
	if (CheckMatrices(Matrix1, Matrix2, 3, 3))
		cout << "Yes, Both matrices are equal ;\n";
	else
		cout << "No, Both matrices are not equal ;\n";


	
	system("pause>0");
	return 0;
}

