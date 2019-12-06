#include "header.h"

void fg_command(char **args)
{
	if (args[1]==NULL)
	{
		printf("More arguments Required\n");
		return ;
	}
	int state;
	pid_t pid = atoi(args[1]);
	int status;
	if( tcsetpgrp(0,pid)<0)
		      perror("tcgetpgrp() error");

	waitpid(pid,&state,WUNTRACED);
	signal(SIGTTOU,SIG_IGN);
	
	if( tcsetpgrp(0,getpid())<0)
		      perror("tcgetpgrp() error");
	signal(SIGTTOU,SIG_DFL);
	return ;

}


void bg_command(char ** args)
{
	if (args[1]==NULL)
	{
		printf("More Arguments Required\n");
		return ;
	}
	pid_t pid = atoi(args[1]);
	if(kill(pid,SIGCONT)<0)
	{
		printf("Background process not found\n");
		return ;
	}
	else
	{
		for (int i = 0; i <u ; ++i)
		{
			if (proc_id[u]==pid)
			{
				proc_id[i]=-1;
				// proc_name[i]="";
			}
		}
	}
	return;

} 