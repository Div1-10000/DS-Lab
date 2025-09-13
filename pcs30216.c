/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
Week 6:----------------------------------------------------------------------------------------------
I. Design an algorithm and write a program to implement stack operations using minimum number
of queues.
Input Format: 
Ask user first whether it wants to push/pop/find the size of the stack, then accordingly perform
operation.
Output Format: 
Output will be the final stack contents if push or pop operation is performed. 
Output will be size of the stack if user asks for size.
------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *queue;
    int front, rear;
    int capacity;
};

struct Queue *Create_Queue(int size)
{
    struct Queue *q1;
    q1 = (struct Queue*)malloc(sizeof(struct Queue));
    q1->capacity = size;
    q1->queue = (int*)malloc(q1->capacity * sizeof(int));
    q1->front = q1->rear = -1;
    return q1;
}

void Enqueue(struct Queue *q1, int value)
{
    if(q1->rear == q1->capacity-1)
    {
        printf("QUEUE OVERFLOW CONDITION!!\n");
        return;
    }
    if(q1->front == -1)
        q1->front = 0;
    q1->queue[++q1->rear] = value;
}

int Dequeue(struct Queue *q1)
{
    if(q1->front == -1)
    {
        printf("QUEUE UNDERFLOW CONDITION!!\n");
        return -1;
    }
    int value = q1->queue[q1->front];
    if(q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
    }
    else
    {
        q1->front++;
    }
    return value;
}

int Empty(struct Queue *q1)
{
    return q1->front == -1;
}

int Full(struct Queue *q1)
{
    return q1->rear == q1->capacity-1;
}

struct Stack
{
    struct Queue *q1;
    struct Queue *q2;
    int size;
};

struct Stack *Create_Stack(int capacity)
{
    struct Stack *s1;
    s1 = (struct Stack*)malloc(sizeof(struct Stack));
    s1->size = capacity;
    s1->q1 = Create_Queue(s1->size);
    s1->q2 = Create_Queue(s1->size);
    return s1;
}

void Push(struct Stack *s1, int value)
{
    if(Full(s1->q1))
    {
        printf("STACK OVERFLOW CONDITION!!\n");
        return;
    }
    Enqueue(s1->q2, value);
    while(!Empty(s1->q1))
    {
        Enqueue(s1->q2, Dequeue(s1->q1));
    }
    struct Queue *temp;
    temp = s1->q1;
    s1->q1 = s1->q2;
    s1->q2 = temp;
}

int Pop(struct Stack *s1)
{
    if(Empty(s1->q1))
    {
        printf("STACK UNDERFLOW CONDITION!!\n");
        return -1;
    }
    return Dequeue(s1->q1);
}

void Display(struct Stack *s1)
{
    if(Empty(s1->q1))
    {
        printf("STACK IS EMPTY!!\n");
        return;
    }
    for(int i = s1->q1->front; i <= s1->q1->rear; i++)
    {
        printf("%d\t", s1->q1->queue[i]);
    }
    printf("\n");
}

void main()
{
    struct Stack *s1;
    int size;
    printf("Enter Size Of Stack: ");
    scanf("%d", &size);
    s1 = Create_Stack(size);
    int choice, value, num;
    printf("\nPRESS(1)>> PUSH\nPRESS(2)>> POP\nPRESS(3)>> DISPLAY\nPRESS(4)>> EXIT\n");
    while(1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Number of Element: ");
                scanf("%d", &num);
                for(int i=0; i<num; i++)
                {
                    printf("Enter Element(%d): ", i+1);
                    scanf("%d", &value);
                    Push(s1, value);
                }
            break;

            case 2:
                printf("Deleted Element: %d", Pop(s1));
            break;

            case 3:
                Display(s1);
            break;

            case 4:
                printf("EXITING....\n");
                exit(0);
            break;

            default:
                printf("INVALID CHOICE\n");
        }
    }
}
/*
OUTPUT:-
---------------------------------------------------------
Enter Size Of Stack: 5  

PRESS(1)>> PUSH
PRESS(2)>> POP
PRESS(3)>> DISPLAY
PRESS(4)>> EXIT

Enter Your Choice: 1
Enter Number of Element: 3
Enter Element(1): 610
Enter Element(2): 427
Enter Element(3): 349

Enter Your Choice: 3
349     427     610

Enter Your Choice: 2
Deleted Element: 349
Enter Your Choice: 3
427     610

Enter Your Choice: 4
EXITING....
---------------------------------------------------------
*/