#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)//child
	{
		sleep(5);
		printf("i am child having id %d\n",getpid());
		printf("my parent's id is %d\n",getppid());
	}
	else if(pid>0)//parent
	{
		wait(NULL);
		printf("i am having parent id %d\n",getpid());
	}
	else
	{
		printf("error");
	
	}
}
