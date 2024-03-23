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
int ReadNumber() {
	int Number;
	cout << "please enter the number to count in Matrix ? \n";
	cin >> Number;
	return Number;
}

int CountNumberInMatrix(int Matrix[3][3],int Number, short Rows, short cols) {
	int Count = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (Number == Matrix[i][j])
			{
				Count++;
			}
		}
	}
	return Count;
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	int Number = ReadNumber();

	
	cout << "Number " << Number << " Count in Matrix is : " << CountNumberInMatrix(Matrix, Number, 3, 3);





	system("pause>0");
	return 0;
}

