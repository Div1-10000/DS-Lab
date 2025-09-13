/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
------------------------------------------------------------------------------------------------------
II. Design an algorithm and write a program to implement queue operations using minimum number
of stacks.
Input Format: 
Ask user first whether it wants to insert into or delete from queue, then accordingly perform
operation.
Output Format: 
Output will be the final queue contents after every operation.
------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int capacity;
    int top;
    int *stack;
};

struct Stack *Create_Stack(int size)

{
    struct Stack *s1;
    s1 = (struct Stack*)malloc(sizeof(struct Stack));
    s1->top = -1;
    s1->capacity = size;
    s1->stack = (int*)malloc(s1->capacity * sizeof(int));
    return s1;
}

void Push(struct Stack *s1, int value)
{
    if(s1->top == s1->capacity-1)
    {
        printf("STACK OVERFLOW CONDITION!!\n");
        return;
    }
    s1->stack[++s1->top] = value;
}

int Pop(struct Stack *s1)
{
    if(s1->top == -1)
    {
        printf("STACK UNDERFLOW CONDITION!!\n");
        return -1;
    }
    return s1->stack[s1->top--];
}

int Empty(struct Stack *s1)
{
    return s1->top == -1;
}

int Full(struct Stack *s1)
{
    return s1->top == s1->capacity-1;
}

struct Queue
{
    struct Stack *s1;
};

struct Queue *Create_Queue(int size)
{
    struct Queue *q1;
    q1 = (struct Queue*)malloc(sizeof(struct Queue));
    q1->s1 = Create_Stack(size);
    return q1;
}

void Enqueue(struct Queue *q1, int value)
{
    if(Full(q1->s1))
    {
        printf("QUEUE OVERFLOW CONDITION!!\n");
        return;
    }
    Push(q1->s1, value);
}

int Recursive_Dequeue(struct Stack *s1)
{
    int x = Pop(s1);
    if(Empty(s1)) 
        return x;
    int res = Recursive_Dequeue(s1);
    Push(s1, x);
    return res;
}

int Dequeue(struct Queue *q1)
{
    if(Empty(q1->s1))
    {
        printf("QUEUE UNDERFLOW CONDITION!!\n");
        return -1;
    }
    return Recursive_Dequeue(q1->s1);
}

void Display(struct Queue *q1)
{
    if(Empty(q1->s1))
    {
        printf("QUEUE IS EMPTY!!\n");
        return;
    }
    for(int i = 0; i <= q1->s1->top; i++)
    {
        printf("%d\t", q1->s1->stack[i]);
    }
}

void main()
{
    struct Queue *q1;
    int size, num;
    printf("Enter Size Of Queue: ");
    scanf("%d", &size);
    q1 = Create_Queue(size);
    int choice, value;
    printf("\nPRESS(1)>> ENQUEUE\nPRESS(2)>> DEQUEUE\nPRESS(3)>> DISPLAY\nPRESS(4)>> EXIT\n");
    while(1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Number Of Elements: ");
                scanf("%d", &num);
                for(int i=0; i<num; i++)
                {
                    printf("Enter Element(%d): ", i+1);
                    scanf("%d", &value);
                    Enqueue(q1, value);
                }
            break;

            case 2:
                printf("Deleted Element: %d",Dequeue(q1));
            break;

            case 3:
                Display(q1);
            break;

            case 4:
                printf("EXITING....");
                exit(0);
            break;

            default:
                printf("\n<<<<<INVALID CHOICE>>>>>\n");
        }
    }
}

/*
Enter Size Of Queue: 5

PRESS(1)>> ENQUEUE
PRESS(2)>> DEQUEUE
PRESS(3)>> DISPLAY
PRESS(4)>> EXIT

Enter Your Choice: 1
Enter Number Of Elements: 3
Enter Element(1): 1
Enter Element(2): 2
Enter Element(3): 3

Enter Your Choice: 3
1       2       3
Enter Your Choice: 2
Deleted Element: 1
Enter Your Choice: 3
2       3
Enter Your Choice: 4
EXITING....
*/