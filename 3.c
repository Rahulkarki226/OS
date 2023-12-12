#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
    pid_t p;
    p=fork();
    if(p==0)
    {
        sleep(3);
        for(int i=0;i<10;i++)
        {
            printf("Child Process %d \n",i);
        }
        exit(0);
    }
    else if(p>0)
    {
        wait(NULL);
        for(int i=0;i<10;i++)
        {
            printf("Parent Process %d\n",i);
        }
    }
    return 0;
}