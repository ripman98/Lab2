#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void jobDone()
{
	printf("Job is done! \n");
}

int main(void)
{
	char name[20];
	for(int i=0;i<4;i++)
	{
		int f = fork();
		if(f==0)
		{
			printf("Enter Name : \n" );
			scanf("%20s", name);
			printf("Your name is %s\n", name);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	jobDone();
	return 0;
}
