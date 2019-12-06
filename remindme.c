#include "header.h"


void remindme(char ** args)
{
	if (args[1]==NULL)
	{
		printf("Enter the seconds\n");
		return ;
	}
	int n = atoi(args[1]);
	int pid = fork();
	if (pid == 0)
	{
		sleep(n);
		printf("\n");
		for(int j=2;args[j]!=NULL;j++)
		printf("%s ",args[j] );
		printf("\n");

	}
	return ;
}
