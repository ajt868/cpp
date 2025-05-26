#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

int *sortarray(int arr[], int size) {
    printf("%d\n", &arr);
    std::sort(arr, arr + size);
    return arr;
}

int *sortArray(int arr[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

queue<int> sortQueue(queue<int> q) {
    queue<int> newQueue;

    int size = q.size();

    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = q.front();
        q.pop();
    }

    arr = sortarray(arr, size);
    for (int i = 0; i < size; i++) {
        newQueue.push(arr[i]);
    }

    return newQueue;
}

void printQueue(queue<int> q) {

    queue<int> newQueue = q;
    int size = q.size();

    cout << "The queue of size " << size << " is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << newQueue.front() << endl;
        newQueue.pop();
    }
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(3);
    q.push(2);
    q.push(8);
    q.push(19);

    q = sortQueue(q);
    printQueue(q);


}