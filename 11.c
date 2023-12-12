#include<stdio.h>
void display(int arr[],int frames){
    int i;
    for(i = 0; i <frames; i++){
        if(arr[i] == -1){
            printf("- ");
        }else{
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
int main()
{
    int incomingStream[]={7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int pageFaults=0;
    int frames=3;
    int pages=sizeof(incomingStream)/sizeof(incomingStream[0]);
    int arr[frames];
    for(int i=0;i<frames;i++)
    {
        arr[i]=-1;
    }
    for(int i=0;i<pages;i++)
    {
        int flag=0;
        for(int j=0;j<frames;j++)
        {
            if(incomingStream[i]==arr[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            pageFaults++;
            arr[(pageFaults-1)%frames]=incomingStream[i];
        }
        display(arr,frames);
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;
}