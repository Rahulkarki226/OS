#include<stdio.h>
typedef struct process
{
    int aT,bT;
}P;
void FCFS(P arr[],int n)
{
    int ct=arr[0].aT,totalwt=0,totaltat=0;
    printf("Process AT BT CT WT TAT\n");
    for(int i=0;i<n;i++)
    {
        if(ct<arr[i].aT)
            ct=arr[i].aT;
        ct+=arr[i].bT;
        int tat=ct-arr[i].aT;
        int wt=tat-arr[i].bT;
        totalwt+=wt;
        totaltat+=tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arr[i].aT,arr[i].bT,ct,wt,tat);
    }
    printf("\nAverage Turn Around Time: %f\nAverage Waiting Time: %f",(float)totaltat/n,(float)totalwt/n);
}
int main()
{
    int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    P arr[n];
    printf("Enter arrival and burst time(sorted):\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&arr[i].aT,&arr[i].bT);
    }
    FCFS(arr,n);
   return 0;
}