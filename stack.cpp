#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

/**
 * Prints the largest element in a non-empty stack.
 * Otherwise notifies the user if the stack is empty.
 */
void printLargestFromStack(stack<int> s) {
    if (s.empty()) {
        printf("The stack is empty. No largest element could be found. \n");
        return;
    }

    int max = s.top();
    int current;

    while (!s.empty()) {
        current = s.top();
        if (current >= max) {
            max = current;
        }
        s.pop();
    }

    printf("The largest element in the stack is %d. \n", max);
}

int getKthElement(stack<int> s, int k) {

    try {
        stack<int> s1 = s;
        int size = s1.size();

        // Check if k is out of valid range
        if (k > size || k < 1) {
            throw out_of_range("Entered position %d is out of valid range");
        }

        int kth_element;
        for (int i = 1; i <= k; i++) {
            if (i == k) {
                break;
            }
            s1.pop();
        }

        kth_element = s1.top();

        return kth_element;

    }

    catch (const out_of_range &e) {
        cout << "Invalid position" 
       // cout << "Invalid position" << endl;
       // cout << "Choose a position between 1 to " << size << endl;
    }
    
    // if (k > size) {
    //     //printf("Entered position is larger than the size of the stack. \n");
    //     throw std::out_of_range("Entered position is larger than the size of the stack.");
    // }


}

int main() {

    stack<int> test0;
    printLargestFromStack(test0);

    stack<int> test1;
    test1.push(1);
    test1.push(0);
    test1.push(-5);
    test1.push(72);
    test1.push(899);
    test1.push(100);

    printLargestFromStack(test1);

    int k = getKthElement(test1, 3);
    printf("The 3rd element of the stack is %d.\n", k);

    k = getKthElement(test1, 4);
    printf("The 4th element of the stack is %d.\n", k);

    k = getKthElement(test1, 7);
    printf("The 7th element of the stack is %d.\n", k);



    stack<string> cars;

    cars.push("Subaru");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda"); // This will be the top element

    int size = cars.size();
    for (int i = 0; i < size; i++) {
        string car = cars.top();
        cars.pop();
        printf("%s\n", car.c_str()); 
    }



    cars.push("Subaru");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda"); // This will be the top element

    while (!cars.empty()) {
        string car = cars.top();
        cars.pop();
        printf("%s\n", car.c_str());
       // cout << car << endl;
    }
    //cout << endl;
}
