

#include <iostream>
#include <iomanip>
using namespace std;




int RandomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random ;
}
void FillMatrixWithRandomNum(int arr[3][3] , int Rows , int cols) {
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintArray(int arr[3][3],int Rows ,int cols) {
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << endl;
    }
}
void sumRowsInMatrix(int arr[3][3],int Rows , int cols) {
    int SumRows = 0;
    cout << "\nThe the following are the sum of each row in the matrix:\n";
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            SumRows += arr[i][j];
        }
        cout << "sum of Rows " << i + 1 << " = " << SumRows << endl;
        SumRows = 0;
    }

    // another method
    cout << endl;
    int counter = 1;
    cout << "\nThe the following are the sum of each row in the matrix:\n";

    cout << "Rows " << counter++ << " sum = " << arr[0][0] + arr[0][1] + arr[0][2] << endl;
    cout << "Rows " << counter++ << " sum = " << arr[1][0] + arr[1][1] + arr[1][2] << endl;
    cout <<"Rows " << counter++ << " sum = " << arr[2][0] + arr[2][1] + arr[2][2] << endl;
}


// method abo-hadhoud
int SumRows(int arr[3][3], short RowNumber, short cols) {
    int sumRows = 0;
    for (short j = 0; j < cols; j++)
    {
        sumRows += arr[RowNumber][j];
    }
    return sumRows;
}
void PrintEachRowSum(int arr[3][3],short Rows , short cols) {
    cout << "\nThe the following are the sum of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++)
    {
        cout << "Rows " << i + 1 << " sum = " << SumRows(arr, i, cols) << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNum(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintArray(arr, 3, 3);
    cout << endl;

    sumRowsInMatrix(arr, 3, 3);
    cout << "\n";

    PrintEachRowSum(arr, 3, 3);
    system("pause>0");
    return 0;
}
