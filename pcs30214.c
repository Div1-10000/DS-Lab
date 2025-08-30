/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
--------------------------------------------------------------------------------------------------------
II. Design an algorithm and write a program to reverse a queue.
Input format: Queue elements are taken as an input.
Output Format: Output will be update reverse queue.
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
    return q1->rear == q1->capacity - 1;
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

int dequeue(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("QUEUE UNDERFLOW CONDITION!!\n");
        return -1;
    }
    int val = q1->queue[q1->front];
    if(q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
    }
    else
    {
        q1->front++;
    }
    return val;
}

void reverse(struct Queue *q1)
{
    if(empty(q1))
        return;
    int x = dequeue(q1);
    reverse(q1);
    enqueue(q1, x);
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
    printf("\n\n");
}

void main()
{
    struct Queue *q1;
    int size, choice;
    printf("Enter Size of Queue: ");
    scanf("%d", &size);
    q1 = initialization(size);
    int num, value;
    printf("Enter Number of Element: ");
    scanf("%d", &num);
    for(int i = 0; i<num; i++)
    {
        printf("Enter Element(%d): ", i+1);
        scanf("%d", &value);
        enqueue(q1, value);
    }
    printf("Original Queue:-------\n");
    display(q1);
    reverse(q1);
    printf("Reversed Queue:-------\n");
    display(q1);
}

/*
---------------------------------------------------
Enter Size of Queue: 5
Enter Number of Element: 5
Enter Element(1): 1
Enter Element(2): 2
Enter Element(3): 3
Enter Element(4): 4
Enter Element(5): 5
Original Queue:-------
1       2       3       4       5

Reversed Queue:-------
5       4       3       2       1
---------------------------------------------------
*/