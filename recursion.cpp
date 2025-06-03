#include <iostream>
using namespace std;


int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    //TODO: Fix error handling
    start:
    printf("Enter a number: ");

    scanf("%d", &n);
    if (n < 0) {
        printf("Number entered is invalid for Fibonacci Sequence. \n");
        printf("Ensure the number is greater than or equal to 0. \n");
        goto start;
    }

    // Print appropriate output for different values of n;
    switch (n)
    {
    case (1):
        /* code */
        printf("The fibonacci value of the %dst value is %d\n", n, fibonacci(n));
        break;  
    case(2):
        printf("The fibonacci value of the %dnd value is %d\n", n, fibonacci(n));
        break;
    case(3):
        printf("The fibonacci value of the %drd value is %d\n", n, fibonacci(n));
        break;
    default:
        printf("The fibonacci value of the %dth value is %d\n", n, fibonacci(n));
    }

    
   
}