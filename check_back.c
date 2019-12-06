#include "header.h"

char *name(int id)
{
	for (int i = 0; i < u; ++i)
	{
		if (proc_id[i]==id)
		{
			return proc_name[i];
		}
	}
}

void check_background()
{
	pid_t p;
	int check;
	while((p=waitpid(-1,&check,WNOHANG))>0)
	{
		if (WIFEXITED(check))
		{
			printf("\n %s with pid: %d exited normally\n",name(p),p );
		}
	}
}