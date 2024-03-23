

#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short cols) {
	int OrderedNumber = 1;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			arr[i][j] = OrderedNumber;
			OrderedNumber++;
		}
	}
}


//second method using array 
void ArrTransposedMatrix(int arr[3][3],int arr2[3][3],short Rows ,  short cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			arr2[i][j] = arr[j][i];
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short cols) {
	cout << endl;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			cout << "  " << arr[i][j] << "       ";
		}
		cout << endl;
	}

}


//method reflect place i to j
void PrintMatrixWithReflectPlace(int arr[3][3], short Rows, short cols) {
	cout << endl;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			//reflect place i to j to resource
			cout << "  " << arr[j][i] << "       ";
		}
		cout << endl;
	}

}

int main()
{
	int arr[3][3], ArrTransposed[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	// ather method just reflect place i to j
	cout << endl << "\nafter transposed matrix \n";
	PrintMatrixWithReflectPlace(arr, 3, 3);


	// another method using second array
	ArrTransposedMatrix(arr , ArrTransposed, 3, 3);

	cout << endl << "\nafter transposed matrix \n\n";
	PrintMatrix(ArrTransposed, 3, 3);
	return 0;
}
