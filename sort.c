#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};



struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* result = NULL;
    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to perform merge sort on a linked list
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* left;
    struct Node* right;

    if (head == NULL || head->next == NULL) {
        return; // Base case: empty or single-node list
    }

    // Split the list into two halves
    left = head;
    right = head->next;

    while (right != NULL) {
        right = right->next;
        if (right != NULL) {
            left = left->next;
            right = right->next;
        }
    }

    struct Node* middle = left->next;
    left->next = NULL;

    // Recursively sort both halves
    mergeSort(&head);
    mergeSort(&middle);

    // Merge the sorted halves
    *headRef = merge(head, middle);
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 2);

    printf("Original Linked List:\n");
    printList(head);

    mergeSort(&head);

    printf("Sorted Linked List:\n");
    printList(head);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
