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
bool AreTypicalMatrices(int Matrix1[3][3],int Matrix2[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];
	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2 \n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);



	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
			cout << "Yes , Both Matrices are  typical ;\n";
	else
	        cout << "No , The Matrices are not typical ;\n";




	system("pause>0");
	return 0;
}

