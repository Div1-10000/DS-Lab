/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
--------------------------------------------------------------------------------------------------------
III. Design an algorithm and write a program to implement Deque i.e. double ended queue. Double
ended queue is a queue in which insertion and deletion can be done from both ends of the queue.
The program should implement following operations:
a) insertFront() - insert an element at the front of Deque
b) insertEnd() - insert an element at the end of Deque
c) deleteFront() - delete an element from the front of Deque
d) deleteEnd() - delete an element from the end of Deque
e) isEmpty() - checks whether Deque is empty or not
f) isFull() - checks whether Deque is full or not
g) printFront() - print Deque from front
h) printEnd() - print Deque from end
Input Format:
Ask user first whether it wants to insert/delete/ at the front or end of the queue, then accordingly
perform operation. 
Output Format: 
Output will be the final queue contents from both directions if enqueue or dequeue operation is
performed.
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
    q1->queue = (int*)malloc(q1->capacity * sizeof(int));
    q1->front = q1->rear = -1;
}

int empty(struct Queue *q1)
{
    return q1->front == -1;
}

int full(struct Queue *q1)
{
    return (q1->rear - q1->front) == q1->capacity-1;
}

void Insert_Front(struct Queue *q1, int value)
{
    if(q1->front <= 0)
    {
        printf("QUEUE IS FULL FROM FRONT SIDE!!\n");
        return;
    }
    q1->queue[--q1->front] = value;
}

void Insert_End(struct Queue *q1, int value)
{
    if(q1->rear == q1->capacity-1)
    {
        printf("QUEUE IS FULL FROM END SIDE!!\n");
        return;
    }
    if(q1->front == -1)
    {
        q1->front = 0;
    }
    q1->queue[++q1->rear] = value;
}

void Delete_Front(struct Queue *q1)
{
    if(q1->front == -1)
    {
        printf("QUEUE UNDERFLOW CONDITION!!\n");
        return;
    }
    if(q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
        return;
    }
    q1->front++;
}

void Delete_End(struct Queue *q1)
{
    if(q1->rear == -1)
    {
        printf("QUEUE UNDERFLOW CONDITION!!\n");
        return;
    }
    if(q1->front == q1->rear)
    {
        q1->front = q1->rear = -1;
        return;
    }
    q1->rear--;
}

int Print_Front(struct Queue *q1)
{
    if(q1->front == -1)
    {
        return -1;
    }
    return q1->queue[q1->front];
}

int Print_End(struct Queue *q1)
{
    if(q1->front == -1)
    {
        return -1;
    }
    return q1->queue[q1->rear];
}

void display(struct Queue *q1)
{
    if(q1->front == -1)
    {
        printf("QUEUE IS EMPTY!!\n");
        return;
    }
    for(int i=q1->front; i<= q1->rear; i++)
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
    int value;
    printf("\nPRESS(1)>> INSERT FRONT\nPRESS(2)>> INSERT END\nPRESS(3)>> DELETE FRONT\n");
    printf("PRESS(4)>> DELETE END\nPRESS(5)>> DISPLAY FRONT\nPRESS(6)>> DISPLAY END\n");
    printf("PRESS(7)>> DISPLAY\nPRESS(8)>> EXIT\n");
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
                Insert_Front(q1, value);
            break;

            case 2:
                printf("Enter Element: ");
                scanf("%d", &value);
                Insert_End(q1, value);
            break;

            case 3:
                Delete_Front(q1);
            break;

            case 4:
                Delete_End(q1);
            break;

            case 5:
                printf("Front Element: %d\n", Print_Front(q1));
            break;

            case 6:
                printf("Rear Element: %d\n", Print_End(q1));
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

PRESS(1)>> INSERT FRONT
PRESS(2)>> INSERT END
PRESS(3)>> DELETE FRONT
PRESS(4)>> DELETE END
PRESS(5)>> DISPLAY FRONT
PRESS(6)>> DISPLAY END
PRESS(7)>> DISPLAY
PRESS(8)>> EXIT

Enter Your Choice: 2

Enter Element: 1

Enter Your Choice: 2

Enter Element: 2

Enter Your Choice: 2

Enter Element: 3

Enter Your Choice: 7

1       2       3

Enter Your Choice: 3


Enter Your Choice: 1

Enter Element: 1

Enter Your Choice: 3


Enter Your Choice: 1

Enter Element: 4

Enter Your Choice: 7

4       2       3

Enter Your Choice: 5

Front Element: 4

Enter Your Choice: 6

Rear Element: 3

Enter Your Choice: 7


4       2       3


Enter Your Choice: 8

EXITING.....
*/