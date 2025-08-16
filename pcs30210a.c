/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
Week 4:------------------------------------------------------------------------------------------
I. Given an empty stack, design an algorithm and a program to reverse a string using this stack
(without recursion).
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be  string of characters.
Output Format: 
The output will have T number of lines. For each test case, output will be new reversed string.
-------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    char *stack;
    int top;
    int size;
};

void create(struct Stack *s1, int capacity)
{
    s1->size = capacity;
    s1->stack = (char*)malloc(s1->size * sizeof(char));
    s1->top = -1;
}

void push(struct Stack *s1, char value)
{
    if(s1->top == s1->size-1)
    {
        printf("STACK OVERFLOW CONDITION!!\n");
        return;
    }
    s1->top++;
    s1->stack[s1->top] = value;
}

char pop(struct Stack *s1)
{
    if(s1->top == -1)
    {
        printf("STACK UNDERFLOW CONDITION!!\n");
        return '\0';
    }
    char temp = s1->stack[s1->top];
    s1->top--;
    return temp;
}

void main()
{
    struct Stack s1;
    int len, test_cases;
    char str[20];
    printf("Enter Test-Cases: ");
    scanf("%d", &test_cases);
    while(test_cases--)
    {
        printf("Enter String: ");
        scanf("%s", str);
        len = strlen(str);
        create(&s1, len);
        for(int i=0; i<len; i++)
        {
            push(&s1, str[i]);
        }
        for(int i=0; i<len; i++)
        {
            str[i] = pop(&s1);
        }
        printf("%s\n\n",str);
    }

}

/*
-----------------------------------------------
Enter Test-Cases: 3
Enter String: Divyanshu
uhsnayviD

Enter String: Neeraj
jareeN

Enter String: Arnav
vanrA
-----------------------------------------------
*/