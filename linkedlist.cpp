#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void printList(ListNode *head) {

    printf("The list printed is: ");

    if (head == NULL) {
        printf("Empty List.\n");
        return;
    }

    else if (head->next == NULL) {
        printf("[%d]\n", head->val);
        return;
    }

    printf("[");
    while (head->next != NULL) {
        printf("%d, ", head->val);
        head = head->next;
    }

    if (head->next == NULL) {
        printf("%d]\n", head->val);
    }
}

/**
 * Function to create a linked list.
 */
ListNode* createList(int n) {

    if (n <= 0) {
        do {
            cout << "Re-enter the size of the list (must be greater than 0): ";
            cin >> n;

            if (n <= 0) {
                cout << "Error: Choose a size greater than 0." << endl;
            }
        } while (n <= 0);
    }
    

    // Let users enter values they want to put in list.
    int *arr = new int[n];

    switch (n)
    {
    case 1:
        printf("Enter the %d value you want to enter into the list. \n", n);
        /* code */
        break;
    
    default:
        printf("Enter the %d values you want to enter into the list. \n", n);
        break;
    }
    

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    struct ListNode *head = new ListNode(arr[0]);

    ListNode *current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    // clean up array memory
    delete [] arr;

    return head;

}

ListNode* reverseList(ListNode* head) {
    // Check if linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* current = head;
    struct ListNode* prev = NULL;

    while (current != NULL) {
        struct ListNode* next = current->next;

        // Swapping logic
        current->next = prev;
        prev = current;
        current = next; 

    }

    return prev;
}

int main() {
    
    int num;
    printf("Enter the length of your desired list: \n");
    cin >> num;
    struct ListNode *head = createList(num);
    
    printList(head);
}