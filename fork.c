#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
       fork();
       printf("Hello AJCE!\n PID=%d\n",getpid());
}
