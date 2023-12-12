#include<stdio.h>
#include<stdbool.h>
#define M 13
#define N 4

typedef struct frame
{
    int data;
    int used;
}F;

bool search(F frame[],int x)
{
    for(int i=0;i<N;i++)
    {
        if(frame[i].data==x)
            return true;
    }
    return false;
}

int lru(int arr[])
{
    int fault=0;
    F frame[N];
    for(int i=0;i<N;i++)
    {
        frame[i].data=-1;
        frame[i].used=-1;
    }
    for(int i=0;i<M;i++)
    {
        bool p=search(frame,arr[i]);
        if(p)
        {
            for(int j=0;j<N;j++)
            {
                if(frame[j].data==arr[i])
                {
                    frame[j].used=i;
                    break;
                }
            }
            printf("%d hit\n",arr[i]);
        }
        else
        {
            fault++;
            int min=0;
            for(int j=0;j<N;j++)
            {
                if(frame[j].data==-1)
                {
                    min=i;
                    break;
                }
                if(frame[min].used>frame[j].used)
                {
                    min=j;
                }
            }
            frame[min].data=arr[i];
            frame[min].used=i;
            printf("%d miss %d %d\n",arr[i],min,i);
        }
    }
    return fault;
}

int main()
{
    int arr[M]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int fault=lru(arr);
    printf("pagefault:%d",fault);
    return 0;
}