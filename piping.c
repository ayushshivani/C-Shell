#include "header.h"

int check_redirection(char ** args)
{
	for (int i = 0; args[i]!=NULL ; ++i)
	{
		if (strcmp(args[i],"<")==0 || strcmp(args[i],">")==0 || strcmp(args[i],">>")==0)
		{
			return 1;
		}
	}
	return 0;
}

void piping(char ** args)
{
	int fd1[2],fd2[2];
	char ** commands = malloc(sizeof(char *)*256);
	int indi_comm=1;
	int flag =0;

	for (int i = 0; args[i]!=NULL ; ++i)
	{
		if (strcmp(args[i],"|")==0)
		{
			indi_comm++;
		}
	}

	int k=0,j=0,cur_com=0;
	for (int i = 0; args[i]!=NULL; ++i)
	{
		// printf("34567\n");
		j=i;
		k=0;
		while(args[j]!=NULL && strcmp(args[j],"|")!=0 )
		{
			commands[k] = args[j];
			k++;
			j++;			
		}
		i=j;
		commands[k]=NULL;
		// for (int l = 0; commands[l]!=NULL ; ++l)
		// 	{
		// 		printf("%s\n",commands[l] );
		// 	}
		// printf("%s\n", commands[0]);
		if (cur_com%2==0)
		{
			
			if (pipe(fd1)==-1)
			{
				printf("Pipe creation failed\n");
				return ;
			}
		}
		else
		{
			if (pipe(fd2)==-1)
			{
				printf("Pipe creation failed\n");
				return ;
			}	

		}
		
		pid_t pid = fork();
		// printf("%d\n",pid );

		if (pid<0)
		{
			if (cur_com != indi_comm - 1)
			{
				if (cur_com % 2 == 0)
				{
					close(fd1[1]); // for odd i
				}
				else{
					close(fd2[1]); // for even i
				} 
			}	
			printf("Child Process Could not be created\n");
			return ;
		}
		if (pid==0)
		{
		// 	printf("2345678987654334567\n");
			if (cur_com == 0)
			{
				dup2(fd1[1],1);
			}
			else if (cur_com == indi_comm - 1)
			{
				if ((cur_com+1)%2==0)
				{
					dup2(fd1[0],0);
				}
				else dup2(fd2[0],0);
			}
			else
			{
				if (cur_com%2==0)
				{
					dup2(fd1[0],0);
					dup2(fd2[1],1);
				}
				else 
				{	
					dup2(fd2[0],0);
					dup2(fd1[1],1);	
				}
			}

			if (check_redirection(commands)==1)
			{
				shell_redirection(commands,0,1,1);
			}
			if (execvp(commands[0],commands)==-1)
			{
				kill(getpid(),SIGTERM);
			}
		}
		if (cur_com==0)
		{
			close(fd1[1]);
		}
		else if (cur_com == indi_comm - 1)
		{
			if ((cur_com+1)%2==0)
			{
				close(fd1[0]);
			}
			else close(fd2[0]);
		}
		else
		{
			if (cur_com%2==0)
			{
				close(fd1[0]);
				close(fd2[1]);
			}
			else 
			{	
				close(fd2[0]);
				close(fd1[1]);	
			}
		}
		waitpid(pid,NULL,0);

		cur_com++;
	}
}
