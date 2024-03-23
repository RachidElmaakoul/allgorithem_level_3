#include <iostream>
using namespace std;

// Function to generate Fibonacci series
void PrintFibonacciUsingLoop() {
    int num1 = 0;
    int num2 = 1;
    int result = 1;
    for (short i = 0; i < 10; i++)
    {
       cout << result << "  "; 
        result = num1 + num2;

        num1 = num2;
        num2 = result;
    }
}

int main() {
   
    PrintFibonacciUsingLoop();

    return 0;
}
