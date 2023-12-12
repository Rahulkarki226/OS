// C program to implement FCFS Disk Scheduling Algorithm
#include<stdio.h>
#include<math.h>
void FCFS(int arr[],int n,int head)
{
    int seekCount=0,currTrack=0;
    for(int i=0;i<n;i++)
    {
        currTrack=arr[i];
        seekCount+=fabs(head-currTrack);
        head=currTrack;
    }
    printf("Total number of seek operations:%d\n",seekCount);
    printf("Seek Sequence is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
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
    FCFS(arr,n,head);
}