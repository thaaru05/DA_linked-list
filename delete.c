
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

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    // Find the node to be deleted and its preceding node
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key was not found in the list
    if (current == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Update the pointers to skip the node to be deleted
    prev->next = current->next;

    // Free memory occupied by the deleted node
    free(current);
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

    // Delete a node
    deleteNode(&head, 2);

    printf("Linked List after Deletion:\n");
    printList(head);

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
