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
			Matrix[i][j] = randomNumber(1, 9);
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


bool IsNumberInMatrix(int Matrix[3][3],short element, short Rows, short cols) {
   for (short i = 0; i < Rows; i++)
   {
	   for (short j = 0; j < cols; j++)
	   {
		   if (Matrix[i][j] == element)
			   return true;
       }
   }
   return false;
}

void PrintIntersectedNumbers(int Matrix[3][3],int Matrix2[3][3], short Rows, short cols) {
	int number;
	for (short i = 0; i < Rows; i++)
	{
		
		for (short j = 0; j < cols; j++)
		{
            number = Matrix[i][j];
			if (IsNumberInMatrix(Matrix2,number, 3, 3))
				cout << setw(3) << number << "    ";
		}
	}

}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3],Matrix2[3][3];

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMatrix 2 : \n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);



	PrintIntersectedNumbers(Matrix, Matrix2, 3, 3);
	cout << endl;



	system("pause>0");
	return 0;
}

