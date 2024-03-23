

#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3],short Rows, short cols) {
	int OrderedNumber = 1;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			arr[i][j] = OrderedNumber;
			OrderedNumber++;
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows , short cols) {
	cout << endl;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			cout << "  " << arr[i][j] << "       ";
		}
		cout << endl;
	}

}

int main()
{
	int arr[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);
	return 0;
}
