/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
------------------------------------------------------------------------------------------------------
III.Given a matrix of size n X n containing positive integers, write an algorithm and a program to
rotate the elements of matrix in clockwise direction.
Input Format: 
First line contains n (the size of matrix).
For next n input lines, each line contains space-separated n integers describing each row of the
matrix.
Output Format:
Output will be rotated matrix.
------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

void rotate_matrix(int arr[][10], int num)
{
    for(int i=0; i<num/2; i++)
    {
        int f=i, l=num-i-1;
        int temp=arr[f][f];
        for(int j=f; j<l; j++)
        {
            arr[j][f]=arr[j+1][f];
        }
        for(int j=f; j<l; j++)
        {
            arr[l][j]=arr[l][j+1];
        }
        for(int j=l; j>f; j--)
        {
            arr[j][l]=arr[j-1][l];
        }
        for(int j=l; j>f+1; j--)
        {
            arr[f][j]=arr[f][j-1];
        }
        arr[f][f+1]=temp;
    }
}
void main()
{
    int num;
    printf("Enter Size of Array: ");
    scanf("%d",&num);
    int arr[10][10];
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int res;
    rotate_matrix(arr, num);
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
/*
-------------------------------------------
Enter Size of Array: 4
11 12 13 14
15 16 17 18
19 20 21 22
23 24 25 26
15      11      12      13
19      20      16      14
23      21      17      18
24      25      26      22
-------------------------------------------
*/