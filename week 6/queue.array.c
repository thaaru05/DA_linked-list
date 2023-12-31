#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int Arr[MAX_SIZE];

int front=-1;
int rear=-1;

void enqueue(int value)
{
    if (rear==MAX_SIZE-1)
	{
        printf("The queue is full\n");
    } 
	else
	{
        if (front==-1)
		{
            front=0;
        }
        rear=rear+1;
        Arr[rear]=value;
    }
}

void dequeue()
{
    if (front==-1)
	{
        printf("Queue is empty\n");
    } 
	else
	{
        printf("Dequeued value: %d\n", Arr[front]);
        if (front==rear)
		{  
            front=-1;
            rear=-1;
        }
		else
		{
            front=front + 1;
        }
    }
}

void display()
{
	int i;
    if (front==-1) 
	{
        printf("Queue is empty\n");
    } else
	{
        printf("Queue elements:");
        for (i=front;i<=rear;i++)
		{
            printf("%d ", Arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE)
	{
        printf("Invalid queue size\n");
        return 1;
    }

    while (1)
	{
        int n, value;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if (rear==MAX_SIZE - 1)
				{
                    printf("The queue is full\n");
                } else {
                    printf("Enter the value:");
                    scanf("%d", &value);
                    enqueue(value);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("THE END\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
