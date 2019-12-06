#include "header.h"

// contains function for redirection

int shell_redirection(char ** args,int fd_in,int fd_out,int par)
{
	char input[1000],output[2000],append[1000];
	int fin=0,fout=0,fapp=0;
	// args[x]=NULL;
	int r =0 ;
	int pid = fork();
	if (pid==0)
	{
		for (int i = 0; args[i]!=NULL ; ++i)
		{
			if (strcmp(args[i],"<")==0)
			{
				strcpy(input,args[i+1]);
				args[i]=NULL;
				fin=1;
			}
			if (args[i]!=NULL)
			{
				if (strcmp(args[i],">")==0)
				{
					strcpy(output,args[i+1]);
					args[i]=NULL;	
					fout=1;
				}
			}

			if (args[i]!=NULL)
			{
				if (strcmp(args[i],">>")==0)
				{
					strcpy(append,args[i+1]);
					args[i]=NULL;	
					fapp=1;
				}
			}
		}
		int fd1,fd2;
		if (fin==1)
		{
			fd1 = open(input,O_RDONLY);
			if (fd1<0)
			{
				printf("Cannot open Input file\n");
				exit(EXIT_FAILURE);
			}
			if (dup2(fd1,fd_in)==-1)
			{
				perror("dup2 failed");
			}
			close(fd1);
		}
		if (fout==1)
		{
			printf("redirection\n");
			fd1 = open(output,O_CREAT  |O_WRONLY | O_APPEND  ,0644);
			if (fd1<0)
			{
				printf("Cannot open/create Output file\n");
				exit(EXIT_FAILURE);
			}
			if (dup2(fd1,fd_out)==-1)
			{
				perror("dup2 failed");
			}
			close(fd1);	
		}
		if (fapp==1)
		{
			fd1 = open(append, O_APPEND | O_WRONLY | O_CREAT ,0777);
			if (fd1<0)
			{
				printf("Cannot open/create Output file\n");
				exit(EXIT_FAILURE);
			}
			if (dup2(fd1,fd_out)==-1)
			{
				perror("dup2 failed");
			}
			close(fd1);	
		}
		if (execvp(args[0],args)<0)	
		{r=1; printf("%s: Command doesn't exist\n", args[0]);}
	}
	else
	{
		wait(NULL);
	}
	if (par)
	{
		kill(getpid(),SIGTERM);
	}

	if (r!=1)
	{
			{printf("%s with process id: %d exited normally\n",args[0],pid);}					

	}
	return 1;
}