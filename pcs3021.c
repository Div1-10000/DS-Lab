#include<stdio.h>
#include<stdlib.h>

void is_function(int arr[], int i, int j)
{
    int temp;
    while(j>i)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

void is_print(int arr[], int num)
{
    for(int i=0; i<num; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void is_left_shift()
{
    int num, k;
    printf("Enter Number: ");
    scanf("%d", &num);
    int arr[num];                               
    for(int i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter value of K: ");
    scanf("%d", &k);
    k=k%num;
    is_function(arr, 0, k-1);
    is_function(arr, k, num-1);
    is_function(arr, 0, num-1);
    is_print(arr, num);
}

void main()
{
    int t;
    printf("Enter Number Of Test Cases: ");
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        is_left_shift();
    }
}