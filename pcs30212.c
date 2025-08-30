/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
--------------------------------------------------------------------------------------------------------
III. Given an expression in the form of postfix representation, design an algorithm and a program to
find result of this expression. 
Input Format: The first line contains number of test cases, T.
For each test case, there will be expression string.
Output Format: The output will have T number of lines. For each test case, output will be the
result of the evaluated expression.
--------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Stack
{
    int *stack;
    int top;
    int size;
};

void create(struct Stack *s1, int capacity)
{
    s1->top = -1;
    s1->size = capacity;
    s1->stack = (int*)malloc(s1->size * sizeof(int));
}

void push(struct Stack *s1, int data)
{
    if(s1->top == s1->size-1)
    {
        printf("STACK OVERFLOW CONDITION!!\n");
        return;
    }
    s1->stack[++s1->top] = data;
}

int pop(struct Stack *s1)
{
    if(s1->top == -1)
    {
        printf("STACK UNDERFLOW CONDITION!!\n");
        return -1;
    }
    return s1->stack[s1->top--];
}

int Postfix(struct Stack *s1, char *str)
{
    for(int i=0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if(ch == ' ' || ch == '\n') continue;
        if(isdigit(str[i]))
        {
            int num = 0;
            while(isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            push(s1, num);
        }
        else
        {
            int val2 = pop(s1);
            int val1 = pop(s1);
            switch(ch)
            {
                case '+':
                    push(s1, val1 + val2);
                break;

                case '-':
                    push(s1, val1 - val2);
                break;

                case '*':
                    push(s1, val1 * val2);
                break;

                case '/':
                    push(s1, val1 / val2);
                break;

                default:
                    printf("INVALID OPERATOR: %c\n", ch);
                    free(s1->stack);
                    return -1;
            }
        }
    }
    int res = pop(s1);
    free(s1->stack);
    return res;
}

void main()
{
    int num;
    printf("Enter Number Of Test-Cases: ");
    scanf("%d", &num);
    getchar();
    struct Stack s1;
    while(num--)
    {
        char str[100];
        printf("Enter Postfix Expression: ");
        fgets(str, sizeof(str), stdin);

        create(&s1, 100);
        printf("RESULT: %d\n\n",Postfix(&s1, str));
    }
}

/*
---------------------------------------------------
Enter Number Of Test-Cases: 3
Enter Postfix Expression: 2 3 1 * + 4-
RESULT: 1

Enter Postfix Expression: 40 8/5*10 2/-
RESULT: 20

Enter Postfix Expression: 40 8/5 2*-
RESULT: -5
---------------------------------------------------
*/