/*
****************************
Name: Divyanshu Sharma 
Section: D1            
Class Roll No.: 34     
****************************
------------------------------------------------------------------------------------------------------
II. Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
algorithm and a program to find which row has maximum number of 1's. (Linear time
complexity)
Input Format: 
First line contains m and n (the size of matrix).
For next m input lines, each line contains space-separated n integers describing each row of the
matrix.
Output Format: 
Output will be row number which has maximum number of 1's. If all the elements of matrix is 0
then print “Not Present”.
------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

int max_once_row(int arr[][10], int row, int column)
{
    int r=0, c=column-1;
    int max=-1;
    while(r<row && c>=0)
    {
        if(arr[r][c]==1)
        {
            max=r;
            c--;
        }
        else
        {
            r++;
        }
    }
    return max;
}

void main()
{
    int row, column;
    printf("Enter Size of Matrix(R*C): ");
    scanf("%d%d", &row, &column);
    int arr[10][10];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int res;
    res=max_once_row(arr, row, column);
    if(res==-1)
    {
        printf("Not Present");
    }
    else
    {
        printf("Row: %d",res+1);
    }
}
/*
-------------------------------------------
Enter Size of Matrix(R*C): 4 3
0 1 1
0 0 1
1 1 1
0 0 0
Row: 3
-------------------------------------------
*/