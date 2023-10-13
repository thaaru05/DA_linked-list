#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};


void findCriticalPoints(struct node *head) {
    int minDistance = -1; 
    int maxDistance = -1; 

    struct node *current = head;

    while (current != NULL && current->next != NULL && current->next->next != NULL) {
    
        if (current->data < current->next->data && current->data < current->next->next->data) {
            
            int distance = 0;
            struct node *temp = current;


            while (temp != NULL && temp->next != NULL) {
                distance++;
                if (temp->data < temp->next->data) {
                    break;
                }
                temp = temp->next;
            }
            if (minDistance == -1 || distance < minDistance) {
                minDistance = distance;
            }

            
            distance = 0;
            while (temp != NULL && temp->next != NULL) {
                distance++;
                if (temp->data < temp->next->data) {
                    break;
                }
                temp = temp->next;
            }
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }

        current = current->next;
    }

    if (minDistance == -1 || maxDistance == -1) {
        printf("[-1, -1]\n");
    } else {
        printf("[%d, %d]\n", minDistance, maxDistance);
    }
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void addNode(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    struct node *head = NULL;

    while (1) {
        int n;
    
        printf("1. Create a node\n");
        printf("2. Add a node\n");
        printf("3. Find critical points\n");
        printf("4. Exit\n");
        printf("Enter the choice:");
        scanf("%d", &n);
        

        switch (n) {
            case 1: {
            	
                int data;
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            }
            case 2: {
                int data;
                printf("Enter the data to add node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            }
            case 3:
                findCriticalPoints(head);
                break;
            case 4:
                return 0;
        }
    }
}

