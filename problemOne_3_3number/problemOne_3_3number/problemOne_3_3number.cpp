
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int randomNumber(int from , int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}
void FillArrayRandomNumber() {
    
        int arr[3][3] = { 
            {randomNumber(1, 100),randomNumber(1, 100),randomNumber(1, 100)},
            { randomNumber(1, 100),randomNumber(1, 100),randomNumber(1, 100)} ,
            { randomNumber(1, 100),randomNumber(1, 100),randomNumber(1, 100) }
        };
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "       ";
        }
        cout << endl;
    }
}
//second methom 
void FillMatrixWithRandomNum(int arr[3][3],int rows,int column) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++) {
            arr[i][j] = randomNumber(1, 100);
        }
    }
}
void printArray(int arr[3][3], int rows, int column) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++) {
            cout << setw(3) << arr[i][j] << "        ";
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    FillArrayRandomNumber();
    cout << endl;



    int arr[3][3];
    FillMatrixWithRandomNum(arr,3,3);
    cout << "\n The following is a 3x3 random matrix:\n";
    printArray(arr, 3, 3);
    return 0;
}

