/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
-------------------------------------------------------------------------------------------------
I. Given an empty stack, design an algorithm and a program to reverse a string using this stack
(with recursion).
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
    s1->top = -1;
    s1->size = capacity;
    s1->stack = (char*)malloc(s1->size * sizeof(char));
}

void push(struct Stack *s1, char data)
{
    if(s1->top == s1->size-1)
    {
        printf("STACK OVERFLOW CONDITION!!\n");
        return;
    }
    s1->top++;
    s1->stack[s1->top] = data;
}

char pop(struct Stack *s1)
{
    char temp;
    if(s1->top == -1)
    {
        printf("STACK UNDRFLOW CONDITION!!\n");
        return '\0';
    }
    temp = s1->stack[s1->top];
    s1->top--;
    return temp;
}

void push_recursion(struct Stack *s1, char str[], int start, int end)
{
    if(start == end)
    {
        return;
    }
    push(s1, str[start]);
    push_recursion(s1, str, start+1, end);
}

void pop_recursion(struct Stack *s1, char str[], int start, int end)
{
    if(start == end)
    {
        return;
    }
    str[start] = pop(s1);
    pop_recursion(s1, str, start+1, end);
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
        push_recursion(&s1, str, 0, len);
        pop_recursion(&s1, str, 0, len);
        printf("%s\n\n", str);
        free(s1.stack);
    }
}

/*
-----------------------------------------------
Enter Test-Cases: 3
Enter String: Divyanshu
uhsnayviD

Enter String: Arnav
vanrA

Enter String: NEERAJ
JAREEN
-----------------------------------------------
*/