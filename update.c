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

// Function to update a node in the linked list
void updateNode(struct Node* head, int oldData, int newData) {
    struct Node* current = head;

    // Traverse the list to find the node with the old data
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData; // Update the data
            return; // Exit the function after updating
        }
        current = current->next;
    }

    // If the node with oldData is not found
    printf("Node with data %d not found.\n", oldData);
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
    // Create nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Original Linked List:\n");
    printList(head);

    // Update a node's data
    updateNode(head, 2, 5);

    printf("Updated Linked List:\n");
    printList(head);

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
