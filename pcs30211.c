/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
--------------------------------------------------------------------------------------------------------
II. Design an algorithm and a program to implement two stacks by using only one array i.e. both the
stacks should use the same array for push and pop operation. Array should be divided in such a
manner that space should be efficiently used if one stack contains very large number of elements
and other one contains only few elements.
Input Format: 
First line will take size of stack.
Second line will ask user whether it wants to push/pop in stack1 or stack2, then accordingly
perform operation.
Output Format: 
Output will be the final contents of both stacks after performing all the operations.
--------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct Stack
{
    int *stack;
    int top1, top2;
    int size;
};

void create(struct Stack *s1, int capacity)
{
    s1->top1 = -1;
    s1->top2 = capacity;
    s1->size = capacity;
    s1->stack = (int*)malloc(s1->size * sizeof(int));
}

void push1(struct Stack *s1, int data)
{
    if(s1->top1 == s1->top2-1)
    {
        printf("STACK(1) OVERFLOW CONDITION!!\n");
        return;
    }
    s1->top1++;
    s1->stack[s1->top1] = data;
}

void pop1(struct Stack *s1)
{
    if(s1->top1 == -1)
    {
        printf("STACK(1) UNDERFLOW CONDITION!!\n");
        return;
    }
    s1->top1--;
}

void push2(struct Stack *s1, int data)
{
    if(s1->top1 == s1->top2-1)
    {
        printf("STACK(2) OVERFLOW CONDITION!!\n");
        return;
    }
    s1->top2--;
    s1->stack[s1->top2] = data;
}

void pop2(struct Stack *s1)
{
    if(s1->top2 == s1->size)
    {
        printf("STACK(2) UNDERFLOW CONDITION!!\n");
        return;
    }
    s1->top2++;
}

void display1(struct Stack *s1)
{
    if(s1->top1 == -1)
    {
        printf("STACK IS EMPTY!!\n");
        return;
    }
    printf("STACK(1): ");
    for(int i=0; i<=s1->top1; i++)
    {
        printf("%d\t", s1->stack[i]);
    }
    printf("\n");
}

void display2(struct Stack *s1)
{
    if(s1->top2 == s1->size)
    {
        printf("STACK IS EMPTY!!\n");
        return;
    }
    printf("STACK(2): ");
    for(int i=s1->top2; i<s1->size; i++)
    {
        printf("%d\t", s1->stack[i]);
    }
    printf("\n");
}

void main()
{
    struct Stack s1;
    int size, choice;
    printf("Enter Size of Stack: ");
    scanf("%d", &size);
    create(&s1, size);
    int value;
    printf("\nPRESS(1)>> PUSH IN STACK(1)\nPRESS(2)>> POP FROM STACK(1)\n");
    printf("PRESS(3)>> PUSH IN STACK(2)\nPRESS(4)>> POP IN STACK(2)\n");
    printf("PRESS(5)>> DISPLAY STACK(1)\nPRESS(6)>> DISPLAY STACK(2)\nPRESS(7)>> EXIT\n\n");
    while(1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Element In Stack(1): ");
                scanf("%d", &value);
                push1(&s1, value);
            break;

            case 2:
                pop1(&s1);
            break;

            case 3:
                printf("Enter Element In Stack(2): ");
                scanf("%d", &value);
                push2(&s1, value);
            break;

            case 4:
                pop2(&s1);
            break;

            case 5:
                display1(&s1);
            break;

            case 6:
                display2(&s1);
            break;

            case 7:
                printf("EXITING......\n");
                exit(0);
            break;

            default:
                printf("INVALID CHOICE!!\n\n");
        }
    }
}
/*
-----------------------------------------------
Enter Size of Stack: 3

PRESS(1)>> PUSH IN STACK(1)
PRESS(2)>> POP FROM STACK(1)
PRESS(3)>> PUSH IN STACK(2)
PRESS(4)>> POP IN STACK(2)
PRESS(5)>> DISPLAY STACK(1)
PRESS(6)>> DISPLAY STACK(2)
PRESS(7)>> EXIT


Enter Your Choice: 1
Enter Element In Stack(1): 1

Enter Your Choice: 1
Enter Element In Stack(1):  
2

Enter Your Choice: 3
Enter Element In Stack(2): 3

Enter Your Choice: 1
Enter Element In Stack(1): 3
STACK(1) OVERFLOW CONDITION!!

Enter Your Choice: 3
Enter Element In Stack(2): 1
STACK(2) OVERFLOW CONDITION!!

Enter Your Choice: 5
STACK(1): 1     2

Enter Your Choice: 6
STACK(2): 3

Enter Your Choice: 7
EXITING......
-----------------------------------------------
*/