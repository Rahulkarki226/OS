// sum of even numbers parent and sum of odd numbers child
#include<stdio.h>
#include<unistd.h>
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    pid_t p=fork();
    int sum=0;
    for(int i=0;i<10;i++)
    {
        // p==0 so we are in child process
        if(p==0 && arr[i]%2==1)
             sum+=arr[i];
        // p>0 so we are in parent process
        else if(p>0 && arr[i]%2==0)
             sum+=arr[i];
    }
    if(p==0)
        printf("Child %d\n",sum);
    else if(p>0)
        printf("parent%d\n",sum);
    
    return 0;
}