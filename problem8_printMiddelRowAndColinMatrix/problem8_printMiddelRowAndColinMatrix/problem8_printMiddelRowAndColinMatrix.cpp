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

void PrintMiddeleColsOfMatrix(int Matrix[3][3], short Rows, short cols) {
	int MiddeleCol = cols / 2;
	
		for (short i = 0; i < cols; i++)
		{
			printf(" %0*d   ", 2, Matrix[i][MiddeleCol]);
		}
}
void PrintMiddeleRowsOfMatrix(int Matrix[3][3], short Rows, short cols) {
	int MiddeleRow = Rows / 2;
	
		for (short i = 0; i < cols; i++)
		{
			 printf(" %0*d   ",2, Matrix[MiddeleRow][i]) ;
		}
}


int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];
	cout << "Matrix : \n";
	FillMatrixWithRandomNumbers(matrix, 3, 3);
	PrintMatrix(matrix, 3, 3);


	cout << "\n middele col of matrix is : \n";
	PrintMiddeleColsOfMatrix(matrix, 3, 3);

	cout << endl;

	cout << "\n middele Row of matrix is : \n";
	PrintMiddeleRowsOfMatrix(matrix, 3, 3);

	cout << "\n\n\n\n\n\n\n";
	system("pause>0");
	return 0;
}

