// C program to implement SSTF Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>

// Function to calculate absolute difference
void calculatedifference(int request[], int head, int diff[][2], int n)
{
    for(int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}

// Function to find minimum absolute difference
int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;

    for(int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

// Function to calculate difference of all 
// tracks and find sequence of disk scheduling
void shortestSeekTimeFirst(int request[], int head, int n)
{
    int diff[n][2];
    for(int i = 0; i < n; i++)
    {
        diff[i][0] = 0;
        diff[i][1] = 0;
    }
    
    int seekcount = 0;
    int seeksequence[n + 1];
    
    for(int i = 0; i < n; i++)
    {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;
        
        seekcount += diff[index][0]; 
        head = request[index];
    }
    seeksequence[n] = head;
    
    printf("Total number of seek operations = %d\n", seekcount);
    printf("Seek sequence is :%d\n");

    for(int i = 0; i <= n; i++) 
    {
        printf("%d\n", seeksequence[i]);
    }
}

// Driver code
int main()
{
    int n;
    printf("Enter number of request:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the request array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int head;
    printf("Enter initial head position:");
    scanf("%d",&head);
    shortestSeekTimeFirst(arr,head,n);
    return 0;
}
