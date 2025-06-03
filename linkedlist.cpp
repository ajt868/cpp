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



ListNode* createList(int n) {
    if (n <= 0) {
        cout << "Error: Cannot create a list of size " << n << endl;
        return NULL; 
    }




}

ListNode* reverseList(ListNode* head) {
    // Check if linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* current = head;
    struct ListNode* prev = NULL;

    while (current != NULL) {
        struct ListNode* next = current->next; // 2

        // Swapping logic
        current->next = prev; // null
        prev = current;       // prev = 1
        current = next;       // 2

    }

    return prev;
}

int main() {
    
    int x = 5;
    string str = to_string(x);

    cout << str << endl;
}