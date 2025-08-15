/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
------------------------------------------------------------------------------------------------------
III.Given a string of opening and closing paranthesis, design an algorithm and a program to find the
length of the longest valid paranthesis substring. Valid paranthesis substring is a string which
contains balanced paranthesis.
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be  string of paranthesis.
Output Format: 
The output will have T number of lines. For each test case, output will be length of longest valid
paranthesis substring.
------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int *stack;
    int top;
    int size;
};

void create(struct Stack *s1, int capacity)
{
    s1->size = capacity;
    s1->stack = (int*)malloc(s1->size * sizeof(int));
    s1->top = -1;
}

void push(struct Stack *s1, int value)
{
    if(s1->size == s1->top+1)
    {
        printf("STACK OVERFLOW CONDITION\n");
        return;
    }
    s1->top++;
    s1->stack[s1->top] = value;
}

void pop(struct Stack *s1)
{
    if(s1->top == -1)
    {
        printf("STACK UNDERFLOW CONDITION\n");
        return;
    }
    s1->top--;
}

int empty(struct Stack *s1)
{
    return s1->top == -1;
}

int is_top(struct Stack *s1)
{
    return s1->stack[s1->top];
}

void longest_valid_paranthesis()
{
    struct Stack s1;
    char str[20];
    printf("Enter Parenthese: ");
    scanf("%s", str);
    int l = strlen(str);
    int temp, max=0;
    create(&s1, l+1);
    push(&s1, -1);
    for(int i=0; i<l; i++)
    {
        if(str[i] == '(') push(&s1, i);
        else if(str[i]==')')
        {
            if(empty(&s1)) push(&s1, i);
            else
            {
                pop(&s1);
                temp = i - is_top(&s1);
                if(temp > max) max = temp;
            }
        }
    }
    printf("Longest Valid Parenthesis: %d\n\n", max);
}

void main()
{
    int test_cases;
    printf("Enter Test-Cases: ");
    scanf("%d", &test_cases);
    for(int i=0; i<test_cases; i++)
    {
        longest_valid_paranthesis();
    }
}

/*
-----------------------------------------------
Enter Test-Cases: 3
Enter Parenthese: ()())))
Longest Valid Parenthesis: 4

Enter Parenthese: ((()())(
Longest Valid Parenthesis: 6

Enter Parenthese: (()()(()))()
Longest Valid Parenthesis: 12
-----------------------------------------------
*/