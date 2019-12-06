#include "header.h"


void set_env(char ** args)
{
	int cnt =0;
	for (int i = 0; args[i]!=NULL ; ++i)
	{
		if (args[i]!=NULL)
		{
			cnt++;
		}
	}
	if (args[2]==NULL)
	{
		args[2]=" ";
	}
	if (cnt==1)
	{
		printf("less arguments given\n");
		return;
	}
	else if (cnt>4)
	{
		printf("Too many arguments\n");
		return ;
	}
	else
		{
			if(setenv(args[1],args[2],1)!=0)
				perror("Unable to set env variable");
		}
		return;
}

void unset_env(char ** args)
{
	int cnt =0;
	for (int i = 0; args[i]!=NULL ; ++i)
	{
		if (args[i]!=NULL)
		{
			cnt++;
		}
	}
	if (cnt ==1)
	{
		printf("Expected more arguments\n");
		return ;
	}
	else
	{
		if(unsetenv(args[1])!=0)
			perror("Unable to unset env variable");	
	}
	return ;
}