#include <stdio.h>
#include <stdlib.h>

int a[20];
int tos=-1;

void push(int v)
{
    tos++;
    a[tos]=v;
}

int pop()
{
    int value=a[tos];
    tos--;
    return value;
}

int main() {
    char exp[20]; //"231*+52*3+*2+"
    printf("Enter:");
    scanf("%s",exp);
    int index;
    int result,a,b;

    for(index=0;exp[index]!='\0';index++)
	{
        if (isdigit(exp[index]))
		{
            push(exp[index] - '0'); 
        } 
		else
		{
            b = pop();
            a = pop();
            switch (exp[index])
			{
                case '*':
                    result=a*b;
                    break;
                case '/':
                    result=a/b;
                    break;
                case '+':
                    result=a+b;
                    break;
                case '-':
                    result=a-b;
                    break;
                default:
                    printf("INVALID\n");
                    return 1;
            }
            push(result);
        }
    }

    if (tos==0)
	{
        printf("Result: %d\n",pop();
    }
	else
	{
        printf("INVALID\n");
    }

    return 0;
}
