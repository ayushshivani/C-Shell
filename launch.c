#include "header.h"

int launch(char ** args)
{
	int background = 0,redirect =0,pipe =0,i = 0;
	char ** temp=malloc(sizeof(char *)*1024	);
	for ( i = 0; args[i]!=NULL; ++i)
	{
		for(int j=0;args[i][j]!='\0';j++)
		{
			if (args[i][j]=='>' || args[i][j]=='<')
			{
				redirect = 1;
			}
			if (args[i][j] == '|')
			{
				pipe = 1;
				// printf("12345\n");
			}
			if (args[i][j]=='&')
			{
				background = 1;
			}
		}

	}
	int j=0;
	if (background==1)
	{
		// printf("fghjk\n");
		for ( i = 0; args[i]!=NULL; ++i)
			{
				if (strcmp(args[i],"&")==0)
				{	
					continue;
				}
				else
				{
					temp[j]=args[i];
					j++;
				}
			}
		for ( i = 0; temp[i] != NULL ; ++i)
			{
				// printf("%s\n",temp[i] );
				args[i]= temp[i];
			}
			for (i = j; args[j] !=NULL ; ++j)
			{

				args[i] = NULL;
			}
				
	}


	if (pipe==1)
	{
		piping(args);
		return 1;
	}
	if (redirect)
	{
		shell_redirection(args,0,1,0);
		return;
	}
	
	int check;
	pid_t pid,wid;
	pid = fork();
	if(background ==1)
	{
		proc_id[u]=pid;	
		strcpy(proc_name[u],args[0]);
		u++;
	}
	
	if (pid<0)
	{
		perror("Forking Error");
	}
	else if (pid==0)
	{
		if (execvp(args[0],args) == -1)
		{
			perror("Could not run the commands");
		}
		exit(0);
 	}
	else
	{
		if (background==0)
		{
			signal(SIGINT,exitHandler);
			signal(SIGTSTP,signHandler);
			wid = waitpid(pid,&check,WUNTRACED);
			if(ky==1)
			{
				kill(pid,9);
				ky=0;
			}
			if(by==1)
			{
				setpgid(pid,pid);
				proc_id[u]=pid;	
				strcpy(proc_name[u],args[0]);
				u++;
				kill(pid,SIGSTOP);
				by=0;
			}
			while(!WIFEXITED(check) && !WIFSIGNALED(check))
			{
				wid = waitpid(pid,&check,WUNTRACED);
				if(ky==1)
				{
					kill(pid,9);
					ky=0;
					break;
				}
				if(by==1)
				{
					setpgid(pid,pid);
					proc_id[u]=pid;	
					strcpy(proc_name[u],args[0]);
					u++;
					kill(pid,SIGSTOP);
					by=0;
					break;
				}
				
			}
				
		}

	}
	return 1;

}