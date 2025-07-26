#include<stdio.h>
#include<stdbool.h>

bool target_found(int arr[][10], int num, int key)
{
    int r=0, c=num-1;
    while(r<num && c>=0)
    {
        if(arr[r][c]==key)
        {
            return true;
        }
        else if(arr[r][c]>key)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    return false;
}
void main()
{
    int num;
    printf("Enter Size of Array: ");
    scanf("%d", &num);
    int arr[10][10];
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int target;
    printf("Enter Target: ");
    scanf("%d", &target);
    if(target_found(arr, num, target))
    {
        printf("Present");
    }
    else
    {
        printf("Not Present");
    }
}