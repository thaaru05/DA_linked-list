#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 
int Arr[MAX_SIZE];
int top=0; 

void push(int size)
{
    int data;
    if (top==size)
	{
        printf("Stack is full\n");
    } 
	else
	{
        scanf("%d", &data);
        Arr[top++]=data;
    }
}

void pop()
{
    if (top==0)
	{
        printf("Stack is empty\n");
    } 
	else
	{
        int var=Arr[--top];
        printf("Popped element is: %d\n", var);
    }
}

void peek() 
{
    if (top==0)
	{
        printf("Stack is empty\n");
    } 
	else
	{
        int var = Arr[top - 1];
        printf("Top element is: %d\n", var);
    }
}

void display()
{
    if (top == 0)
	{
        printf("Stack is empty\n");
    }
	else
	{
    	int i;
        printf("Stack elements: ");
        for (i = 0; i < top; i++)
		{
            printf("%d ", Arr[i]);
        }
        printf("\n");
    }
}
int min()
{ 
    int length = sizeof(Arr)/sizeof(Arr[0]);        
    int min = Arr[0];
    int i;
    for (i = 0; i < length; i++) {    
       if(Arr[i] < min)    
           min = Arr[i];    
    }      
    printf("Smallest element present in given array: %d\n", min);    
    return 0;    
}
int main()
{
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE)
	{
        printf("Invalid stack size\n");
        return 1;
    }

    while (1) 
	{
        int n;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Print the min\n");
		printf("6. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                push(size);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
            	min();
            	break;
            case 6:
            	printf("THE END\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
