/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
Week 3:----------------------------------------------------------------------------------------------
I. Design an algorithm and a program to implement stack using array. The program should
implement following stack operations:
a) Create() - create an empty stack.
b) Push(k) - push an element k into the stack.
c) Pop() - pop an element from the stack snd return it
d) IsEmpty() - check if stack is empty or not
e) Size() - finds the size of the stack
f) Print() - prints the contents of stack
Input Format: 
Ask user first whether it wants to push/pop/find the size of the stack, then accordingly perform
operation.
Output Format: 
Output will be the final stack contents if push or pop operation is performed. Output will be size
of the stack if user asks for size.
------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct Stack
{
    int *stack;
    int top;
    int capacity;
};

struct Stack *create(int size)
{
    struct Stack *s1;
    s1 = (struct Stack*)malloc(sizeof(struct Stack));
    s1->capacity = size;
    s1->stack = (int*)malloc(s1->capacity * sizeof(int));
    s1->top = -1;
    return s1;
}

int empty(struct Stack *s1)
{
    return s1->top == -1;
}

void push(struct Stack *s1, int data)
{
    if(s1->top == s1->capacity-1)
    {
        printf("STACK OVERFLOW CONDITITON\n");
        return;
    }
    s1->top++;
    s1->stack[s1->top] = data;
}

int pop(struct Stack *s1)
{
    if(empty(s1))
    {
        printf("STACK UNDERFLOW CONDITION\n");
        return -1;
    }
    int temp = s1->stack[s1->top];
    s1->top--;
    return temp;
}

int size(struct Stack *s1)
{
    return s1->top+1;
}

void display(struct Stack *s1)
{
    if(empty(s1))
    {
        printf("STACK IS EMPTY!!\n");
        return;
    }
    for(int i=0; i<=s1->top; i++)
    {
        printf("%d\t", s1->stack[i]);
    }
    printf("\n");
}

void main()
{
    struct Stack *s1;
    int siz, choice, value;
    printf("Enter Size of Stack: ");
    scanf("%d", &siz);
    int num;
    s1 = create(siz);
    printf("PRESS(1)>> PUSH\nPRESS(2)>> POP\nPRESS(3)>> SIZE\nPRESS(4)>> EXIT\n");
    while(1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &value);
                push(s1, value);
                printf("STACK: ");
                display(s1);
            break;

            case 2:
                num = pop(s1);
                if(num != -1)
                {
                    printf("Deleted Element: %d", num);
                }
            break;

            case 3:
                printf("Size: %d", size(s1));
            break;

            case 4:
                printf("EXITING.....");
                exit(0);
            break;

            default:
                printf("INVALID CHOICE\n");
        }
    }
    
}

/*
-----------------------------------------------
Enter Size of Stack: 5
PRESS(1)>> PUSH
PRESS(2)>> POP
PRESS(3)>> SIZE
PRESS(4)>> EXIT

Enter Your Choice: 1

Enter Element: 34
STACK: 34

Enter Your Choice: 1

Enter Element: 42
STACK: 34       42

Enter Your Choice: 1

Enter Element: 6
STACK: 34       42      6

Enter Your Choice: 3

Size: 3
Enter Your Choice: 4

EXITING.....
-----------------------------------------------
*/
