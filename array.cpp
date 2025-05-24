#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define INDEX_BREAK 2
#define THREE 3

// void sorting(int arr[], int n) {
//     int size = sizeof(*arr)/sizeof(arr[0]);

//     for (int j = 0; j < n; j++) {
//         for (int i = 0; i < n - 1; i++) {
//             if (arr[i] >= arr[i + 1]) {
//                 int temp = arr[i + 1];
//                 arr[i + 1] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }

//     printf("[");
//     for (int i = 0; i < n - 1; i++) {
//         printf("%d,", arr[i]);
//     }
//     printf("%d]", arr[n - 1]);
//     cout << endl;
// }

/**
 * Returns a sorted version of the array
 */
int* sorting(int arr[], int n) {
    int size = sizeof(*arr)/sizeof(arr[0]);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

/**
 * Helper function to print the array
 */
void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("%d,", arr[i]);
    }
    printf("%d]", arr[n - 1]);
    cout << endl;
}

/**
 * Helper function to find the desired element with regards to size
 * E.g. find_element_order(arr[], n, 3) finds the 3rd largest element in the array
 */
int find_element_order(int arr[], int n, int order) {
    arr = sorting(arr, n);
    int index = n - order;

    return arr[index];
}

/**
 * Helper function which finds the second largest element independent of the sorting algorithm
 */
int find_2nd_largest(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] >= max) {
            max = arr[i];
        }
    }
    
    int second = arr[0];
    for (int i = 0; i < n; i++) {
        if ((arr[i] >= second) && (arr[i] != max)) {
            second = arr[i];
        }
    }

    return second;
}


/**
 * Helper function to sort the odd-even separated array
 */
int* sort_odd_then_even(int arr[], int n, int last_odd_index) {
    for (int j = 0; j <= last_odd_index; j++) {
        for (int i = 0; i <= last_odd_index - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int j = last_odd_index + 1; j < n; j++) {
        for (int i = last_odd_index + 1; i < n - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }

    return arr;
}

/**
 * Separates the array into odd numbers and then even numbers
 *  // arr[5] = {1,16,28,33,111};
    // even_count = 2; odd_count = 3;
    // desired result = {1,33,111,16,28}
 */

int* separate_even_odd(int arr[], int n) {
    arr = sorting(arr, n);
    int even_count = 0;
    int odd_count = n - even_count;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_count = even_count + 1;
        }
    }

    int last_odd_index = n - even_count - 1;

    for (int i = 0; i <= last_odd_index; i++) {
        for (int j = last_odd_index; j < n; j++) {
            if ((arr[i] % 2 == 0) && (arr[j] % 2 == 1)) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    arr = sort_odd_then_even(arr, n, last_odd_index);

    return arr;
}

/**
 * Helper function to get the number of unique elements in the array
 */
int get_num_unique_elements(int arr[], int n) {
    arr = sorting(arr, n);
    int num_unique_elements = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i + 1]) {
            continue;
        }
        num_unique_elements++;
    }

    return num_unique_elements;
}

/**
 * Function to help find unique elements
 */
int* get_unique_elements(int arr[], int size, int num_unique_elements) {

    int *sup_array = new int[num_unique_elements];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == arr[i + 1]) {
            continue;
        }
        sup_array[count] = arr[i];
        count++;
    }

    return sup_array;
}

int* get_three_largest_elements(int arr[], int n) {
    int *three_elements = new int[3];
    int index = 0;
    int num_unique_elements = get_num_unique_elements(arr, n);

    if (num_unique_elements < 3) {
        get_unique_elements(arr, n, num_unique_elements);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (index > INDEX_BREAK) {
            break;
        }

        // Skip recurring elements in the sorted array
        if (arr[i] == arr[i + 1]) {
            continue;
        }

        three_elements[index] = arr[i];
        index = index + 1;
    }

    

    // printf("Array has only %d distinct elements\n", num_unique_elements);

    // Handle cases where the array has less than 3 unique elements
   
    return three_elements;
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the size of your array: " << endl;
    cin >> n; 
    
    int *arr = new int[n];

    cout << "Your randomised array of size " << n << " is:" << endl;

    printf("[");
    for (int i = 0; i < n - 1; i++) {
        arr[i] = rand() % 101;
        printf("%d,", arr[i]);
    }

    arr[n - 1] = rand() % 101;
    printf("%d]", arr[n - 1]);
    cout << endl;

    printf("Now, the sorted version of the array is: \n");
    arr = sorting(arr, n);
    print_array(arr, n);

    int second = find_2nd_largest(arr, n);
    printf("The second largest element of the array is %d\n", second);

    printf("The third largest element of the array is %d\n", find_element_order(arr, n, 3));

    printf("The even-odd sorted array is: \n");
    int *arr2 = separate_even_odd(arr, n);
    print_array(arr2, n);

    int arr4[4] = {3, 5, 5, 7};
    int arr5[3] = {6,3,3};

    // Not working for this test case
    int arr6[3] = {1,1,1};

    int *arr3 = get_three_largest_elements(arr4, 4);

    print_array(arr3, THREE);
    print_array(get_three_largest_elements(arr5, 3), 2);

    print_array(get_three_largest_elements(arr6, 2), 2);
}
