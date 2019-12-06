#include "header.h"

// cd function
int build_cd(char ** args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument\n");
	}
	else
	{

		// printf("%s\n",root);
		if (strcmp(args[1],"~")==0)
		{
			chdir(root);
		}
		else if (chdir(args[1])!=0)
		{
			fprintf(stderr, "directory not found\n");
		}
	}
	return 1;
}


int build_pwd(char ** args)
{
	char cwd[200];

	if (getcwd(cwd,sizeof(cwd))== NULL)
	{
		perror("getcwd() error");
	}
	else
	{
		printf("%s\n",cwd);
	}
}


int build_echo(char ** args)
{
	if (args[1]==NULL)
	{
		printf("\n");
		return 1;
	}
	for (int i = 1; args[i]!=NULL; ++i)
	{
		printf("%s ",args[i] );
	}
	printf("\n");
	return 0;
}