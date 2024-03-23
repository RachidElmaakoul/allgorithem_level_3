// problem3_SumEachRowsInMatrixInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int randomNumber(int from, int to) {
	int random = rand() % (to - from + 1) + from;
	return random;
}

void FillWithMatrixNum(int arr[3][3] , short Rows , short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			arr[i][j] = randomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3],short Rows , short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}
int SumRows(int arr[3][3] , short NumberOfRows , short cols) {
	int sum = 0;
	for (short c = 0; c < cols; c++)
	{
		sum += arr[NumberOfRows][c];
	}
	return sum;
}
void printEachSumRow(int arr[3][3],int arrSum[3], short Rows , short cols) {
	for (short i = 0; i < Rows; i++)
	{
		arrSum[i] = SumRows(arr, i, cols);
	}
}
void PrintCopyArray(int arrSum[3], int length) {
	cout << "\nThe the following are the sum of each row in the matrix:\n";
	for (short i = 0; i < length; i++)
	{
		cout << "rows " << i + 1 << " sum = " << arrSum[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3],arrSum[3];
	FillWithMatrixNum(arr, 3, 3);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);
	
	printEachSumRow(arr, arrSum, 3, 3);
	PrintCopyArray(arrSum , 3);



	return 0;

}

