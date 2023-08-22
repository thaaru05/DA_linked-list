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

// Function to search for a specific value in the linked list
struct Node* search(struct Node* head, int target) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return current; // Node with target value found
        }
        current = current->next;
    }

    return NULL; // Node with target value not found
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

    int target = 4;
    struct Node* result = search(head, target);

    if (result != NULL) {
        printf("Node with value %d found.\n", target);
    } else {
        printf("Node with value %d not found.\n", target);
    }

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
