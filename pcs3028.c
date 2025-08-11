#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    char *stack;
    int top;
    int size;
};

void create(struct Stack *s1, int len)
{
    s1->size = len;
    s1->top = -1;
    s1->stack = (char*)malloc((s1->size)*sizeof(char));
}

void push(struct Stack *s1, char value)
{
    if(s1->top == s1->size-1)
    {
        printf("Stack Overflow Condition!!\n");
        return;
    }
    s1->top++;
    s1->stack[s1->top] = value;
}

char pop(struct Stack *s1)
{
    char left;
    if(s1->top == -1)
    {
        printf("Underflow Condition");
        return '\0';
    }
    left = s1->stack[s1->top];
    s1->top--;
    return left;
}

int empty(struct Stack *s1)
{
    return s1->top == -1;
}

void free_function(struct Stack *s1)
{
    while(s1->stack != NULL)
    {
        free(s1->stack);
        s1->stack = NULL;
    }
    s1->top = -1;
    s1->size = 0;
}

int is_valid_parentheses(char *str, int len)
{
    struct Stack s1;
    create(&s1, len);
    char left, right;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='{' || str[i]=='(' ||str[i]=='[')
        {
            push(&s1, str[i]);
        }
        else if(str[i]=='}'|| str[i]==']'|| str[i]==')')
        {
            if(empty(&s1))
            {
                return 0;
            }
            left = pop(&s1);
            right = str[i];
            if((left == '{' && right == '}') ||
               (left == '(' && right == ')') ||
               (left == '[' && right == ']'))
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    int res;
    res =  empty(&s1);
    free_function(&s1);
    return res;
}

void main()
{
    int test_cases;
    printf("Enter Number of Test Cases: ");
    scanf("%d", &test_cases);
    while(test_cases>0)
    {
        char str[20];
        int l, res;
        printf("Enter Parentheses: ");
        scanf("%s", str);
        l= strlen(str);
        res=is_valid_parentheses(str, l);
        if(res==1)
        {
            printf("Balanced\n");
        }
        else
        {
            printf("Unbalanced\n");
        }
        test_cases--;
    }
}