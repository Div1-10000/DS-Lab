#include<stdio.h>
#include<stdlib.h>

int is_odd(int arr[], int num)
{
    int ans=0;
    for(int i=0; i<num; i++)
    {
        ans^=arr[i];
    }
    return ans;
}
void is_input()
{
    int num;
    printf("Enter Number: ");
    scanf("%d", &num);
    int arr[num];
    for(int i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d\n",is_odd(arr, num));
}

void main()
{
    int t;
    printf("Enter Number Of Test Cases: ");
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        is_input();
    }
}