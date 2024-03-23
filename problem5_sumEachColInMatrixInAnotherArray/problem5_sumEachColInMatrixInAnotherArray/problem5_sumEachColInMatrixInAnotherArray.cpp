
#include <iostream>
#include <iomanip>
using namespace std;

int randomNumber(int from, int to) {
	int random = rand() % (to - from + 1) + from;
	return random;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			arr[i][j] = randomNumber(1, 100);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			cout << setw(3) << arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int SumColumn(int arr[3][3], short Rows, short ColNumber) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}
void SumEachColInArray(int arr[3][3],int SumArray[3], short Rows, short cols) {
	cout << "\nThe the following are the sum of each col in the matrix:\n";
	for (short i = 0; i < cols; i++)
	{
		SumArray[i] = SumColumn(arr, Rows, i);
	}
}
void PrintSumCoLInArray(int SumArray[3],short Col) {
	for (short i = 0; i < Col; i++)
	{
cout << "col " << i + 1 << " sum = " << setw(3) << SumArray[i] <<  endl;
	}
}
//second Method 
int sumEachColsInMatrix(int arr[3][3], int arrSum[3], short Rows, short cols) {
	int sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			sum += arr[j][i];
		}
		arrSum[i] = sum;
		sum = 0;
	}
	return arrSum[3];
}

void SumEachColInArray(int arrSum[3], short cols) {
	cout << "\nThe the following are the sum of each col in the matrix:\n";
	for (short i = 0; i < cols; i++)
	{
		cout << "col " << i + 1 << " sum = " << setw(3) << arrSum[i] << endl;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arrSum[3];
	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	SumColumn(arr, 3, 3);
	SumEachColInArray(arr,arrSum, 3, 3);
	PrintSumCoLInArray(arrSum, 3);

	cout << endl;
	sumEachColsInMatrix(arr, arrSum, 3, 3);
	SumEachColInArray(arrSum, 3);



	return 0;
}

