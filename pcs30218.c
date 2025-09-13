/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
------------------------------------------------------------------------------------------------------
III. Design an algorithm and write a program to implement circular queue. Circular queue is a queue
in which last position of queue is connected with first position of queue to make a circle. The
program should implement following operations:
a) Create() - create a queue of specific size
b)EnQueue(k) - insert an element k into the queue
c) DeQueue() - delete an element from the queue
d)IsEmpty() - check if queue is empty or not
e) Front() - return front item from queue
f) Rear() - return rear item from queue
Input Format:
Ask user first whether it wants to insert/delete/find front or rear of the queue, then accordingly
perform operation.
Output Format: 
Output will be the final queue contents after every operation is performed. 
Output will be front/rear item of the queue if user asks for it.
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

struct Queue *initialize_queue(int size)
{
    struct Queue *q1;
    q1 = (struct Queue*)malloc(sizeof(struct Queue));
    q1->capacity = size;
    q1->queue = (int*)malloc(q1->capacity*sizeof(int));
    q1->front = q1->rear = -1;
    return q1;
}

int full(struct Queue *q1)
{
    return (q1->rear+1)% (q1->capacity ) == q1->front;
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
    q1->rear = (q1->rear+1)%(q1->capacity);
    q1->queue[q1->rear] = value;
}

void dequeue(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("QUEUE UNDERFLOW CONDITION\n");
        return;
    }
    if(q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
        return;
    }
    q1->front = (q1->front+1)%(q1->capacity);
}

int front(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    return q1->queue[q1->front];
}

int rear(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    return q1->queue[q1->rear];
}

void display(struct Queue *q1)
{
    if(empty(q1))
    {
        printf("EMPTY!!\n");
        return;
    }
    for(int i = q1->front; i != q1->rear; i = (i + 1) % q1->capacity)
    {
        printf("%d\t", q1->queue[i]);
    }
    printf("%d\n", q1->queue[q1->rear]);
}

void main()
{
    struct Queue *q1;
    int size, choice;
    printf("Enter Size of Queue: ");
    scanf("%d", &size);
    q1 = initialize_queue(size);
    int value, num, num1;
    printf("\nPRESS(1)>> ENQUEUE\nPRESS(2)>> DEQUEUE\nPRESS(3)>> DISPLAY\nPRESS(4)>> FRONT\n");
    printf("PRESS(5)>> REAR\nPRESS(6)>> EMPTY\nPRESS(7)>> FULL\nPRESS(8)>> EXIT\n");
    while(1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("Enter Number of Elements: ");
                scanf("%d", &num);
                for(int i=0; i<num; i++)
                {
                    printf("Enter Element(%d): ", i+1);
                    scanf("%d", &value);
                    enqueue(q1, value);
                }
            break;

            case 2:
                dequeue(q1);
            break;

            case 3:
                display(q1);
            break;

            case 4:
                num1 = front(q1);
                printf("Front = %d\n", num1);
            break;

            case 5:
                num1 = rear(q1);
                printf("Rear = %d\n", num1);
            break;

            case 6:
                if(empty(q1))
                {
                    printf("QUEUE IS EMPTY!!\n");
                }
                else
                {
                    printf("QUEUE IS NOT EMPTY!!\n");
                }
            break;

            case 7:
                if(full(q1))
                {
                    printf("QUEUE IS FULL!!\n");
                }
                else
                {
                    printf("QUEUE IS NOT FULL!!\n");
                }
            break;

            case 8:
                printf("EXTING........\n");
                exit(0);
            break;

            default:
                printf("\nINVALID CHOICE\n");
        }
    }
}

/*
OUTPUT:-
---------------------------------------------------------
Enter Size of Queue: 5

PRESS(1)>> ENQUEUE
PRESS(2)>> DEQUEUE
PRESS(3)>> DISPLAY
PRESS(4)>> FRONT
PRESS(5)>> REAR
PRESS(6)>> EMPTY
PRESS(7)>> FULL
PRESS(8)>> EXIT

Enter Your Choice: 1
Enter Number of Elements: 5
Enter Element(1): 1
Enter Element(2): 2
Enter Element(3): 3
Enter Element(4): 4
Enter Element(5): 5

Enter Your Choice: 2

Enter Your Choice: 3
2       3       4       5

Enter Your Choice: 1
Enter Number of Elements: 1
Enter Element(1): 6

Enter Your Choice: 3
2       3       4       5       6

Enter Your Choice: 8
EXTING........
---------------------------------------------------------
*/