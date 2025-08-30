/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
Week 5:-------------------------------------------------------------------------------------------------
I. Design an algorithm and a program to implement queue using array. The program should
implement following queue operations:
a) Create() - create a queue
b) EnQueue(k) - insert an element k into the queue
c) DeQueue() - delete an element from the queue
d) IsEmpty() - check if queue is empty or not
e) Size() - finds the size of the queue
Input Format: 
Ask user first whether it wants to insert/delete/find size of the queue, then accordingly perform
operation.
Output Format: 
Output will be the final queue contents after every operation is performed. 
Output will be size of the queue if user asks for size.
--------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *queue;
    int front, rear;
    int capacity;
};

struct Queue *initialization(int size)
{
    struct Queue *q1;
    q1 = (struct Queue*)malloc(sizeof(struct Queue));
    q1->capacity = size;
    q1->front = q1->rear = -1;
    q1->queue = (int*)malloc(sizeof(int) * q1->capacity);
    return q1;
}

int full(struct Queue *q1)
{
    return (q1->rear - q1->front) == q1->capacity-1;
}

int empty(struct Queue *q1)
{
    return q1->front == -1;
}

void enqueue(struct Queue *q1, int value)
{
    if(full(q1))
    {
        printf("QUEUE OVERFLOW CONDITION!!\n");
        return;
    }
    if(empty(q1))
    {
        q1->front = 0;
    }
    q1->queue[++q1->rear] = value;
}

void dequeue(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("QUEUE UNDERFLOW CONDITION!!\n");
        return;
    }
    if(q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
        return;
    }
    q1->front = q1->front+1;
}

int is_size(struct Queue *q1)
{
    if(empty(q1))
    {
        return 0;
    }
    return q1->rear - q1->front + 1;
}

void display(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("QUEUE IS EMPTY!!\n");
        return;
    }
    for(int i = q1->front; i <= q1->rear; i++)
    {
        printf("%d\t", q1->queue[i]);
    }
}

int is_front(struct Queue *q1)
{
    return q1->queue[q1->front];
}

void main()
{
    struct Queue *q1;
    int size, choice;
    printf("Enter Size of Queue: ");
    scanf("%d", &size);
    q1 = initialization(size);
    int value;
    printf("\nPRESS(1)>> ENQUEUE\nPRESS(2)>> DEQUEUE\nPRESS(3)>> FULL\nPRESS(4)>> EMPTY\nPRESS(5)>> SIZE\n");
    printf("PRESS(6)>> FRONT\nPRESS(7)>> DISPLAY\nPRESS(8)>> EXIT\n");
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
                enqueue(q1, value);
            break;

            case 2:
                dequeue(q1);
            break;

            case 3:
                if(full(q1))
                {
                    printf("QUEUE IS FULL!!\n");
                }
                else
                {
                    printf("QUEUE IS NOT FULL\n");
                }
            break;

            case 4:
                if(empty(q1))
                {
                    printf("QUEUE IS EMPTY!!\n");
                }
                else
                {
                    printf("QUEUE IS NOT EMPTY\n");
                }
            break;

            case 5:
                printf("%d", is_size(q1));
            break;

            case 6:
                printf("%d", is_front(q1));
            break;

            case 7:
                display(q1);
            break;

            case 8:
                printf("EXITING.....\n");
                exit(0);
            break;

            default:
                printf("INVALID CHOICE\n");
        }
    }
}

/*
Enter Size of Queue: 5

PRESS(1)>> ENQUEUE
PRESS(2)>> DEQUEUE
PRESS(3)>> FULL
PRESS(4)>> EMPTY
PRESS(5)>> SIZE
PRESS(6)>> FRONT
PRESS(7)>> DISPLAY
PRESS(8)>> EXIT

Enter Your Choice: 1

Enter Element: 1

Enter Your Choice: 1

Enter Element: 2

Enter Your Choice: 1

Enter Element: 3

Enter Your Choice: 7

1       2       3
Enter Your Choice: 2


Enter Your Choice: 7

2       3
Enter Your Choice: 3

QUEUE IS NOT FULL

Enter Your Choice: 4

QUEUE IS NOT EMPTY

Enter Your Choice: 5

2
Enter Your Choice: 6

2
Enter Your Choice: 7

2       3
Enter Your Choice: 8

EXITING.....
*/