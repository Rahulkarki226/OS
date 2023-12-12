#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
void *thread_function(void *arg);
int i,j;
int main()
{
    pthread_t thread;
    pthread_create(&thread,NULL,thread_function,NULL);
    pthread_join(thread,NULL);
    printf("Inside the main program\n");
    for(j=20;j<25;j++)
    {
        printf("%d\n",j);
        sleep(1);
    }
}
void *thread_function(void *arg)
{
  printf("Inside Thread\n");
  for(i=0;i<5;i++)
  {
      printf("%d\n",i);
      sleep(10);
  }
}