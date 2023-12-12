#include<stdio.h>
#include<limits.h>
typedef struct process{
    int aT,bT,cT,tAT,wT,completed;
}P;

int sort(P arr[],int n,int t)
{
    int minIndex=-1;
    int minBurst=INT_MAX;
    for(int i=0;i<n;i++){
        if(!arr[i].completed && arr[i].aT<=t && arr[i].bT<minBurst){
            minBurst = arr[i].bT;
            minIndex = i;
        }
    }
    return minIndex;
}

void SJF(int n,P arr[]){
    int currentTime = 0;
    int completedProcess =0;
    while(completedProcess<n){
        int minIndex = sort(arr,n,currentTime);
        if(minIndex==-1){
            currentTime++;
        }
        else{
            arr[minIndex].cT = arr[minIndex].bT + currentTime;
            arr[minIndex].tAT = arr[minIndex].cT - arr[minIndex].aT;
            arr[minIndex].wT = arr[minIndex].tAT - arr[minIndex].bT;
            arr[minIndex].completed =1;
            completedProcess++;
            currentTime = arr[minIndex].cT;
            printf("P[%d] \t\t %d \t %d \t %d \t %d \t %d\n",(minIndex+1),(arr[minIndex].aT),(arr[minIndex].bT),(arr[minIndex].cT),(arr[minIndex].tAT),(arr[minIndex].wT));
        }
    }
}

int main(){
    int n;
    float aTAT=0,aWT=0;
    printf("Enter total number of process: ");
    scanf("%d",&n);
    P arr[n];
    printf("Enter arrival time and burst time of processes:\n");
    for(int i=0;i<n;i++){
        printf("P[%d]: ",(i+1));
        scanf("%d %d",&arr[i].aT,&arr[i].bT);
        arr[i].completed=0;
    }
    printf("Gantt Chart:\n");
    printf("Process \t AT \t BT \t CT \t TAT \t WT\n");
    SJF(n,arr);
    for(int i=0;i<n;i++){
        aTAT+=arr[i].tAT;
        aWT+=arr[i].wT;
    }
    printf("Average Turn Around Time = %f\n",(aTAT/(float)n));
    printf("Average Waiting Time = %f\n",(aWT/(float)n));

    return 0;
}
