#include "header.h"

void jobs(char ** args)
{
	char ** con_word = malloc(sizeof(char)*1024);
	char c[100];
	size_t size;
	char status[100];
	char s[100];
	
	char file_content[100024];
	for (int i = 0; i < u; ++i)
	{
		sprintf(c,"/proc/%d/status",proc_id[i]);
		FILE *ftpr = fopen(c,"r");
		if (ftpr==NULL)
		{
			// printf("cannot open file\n");
			// exit(0);
			continue;
		}
		else
		{
			fseek(ftpr,0,SEEK_SET);
			size =fread(file_content,sizeof(char),10000,ftpr);
			if (size<0)
			{
				printf("Error finding process %s\n",proc_name[i]);
				exit(0);
			}
			else
			{
				if (file_content[size-1]=='\n')
				{
					file_content[size-1] = '\0';
				}
			}
		}
		con_word = parse_line(file_content);
		for (int i = 0; con_word[i]!=NULL ; ++i)
		{
		
			if (strcmp(con_word[i],"State:")==0)
			{
				strcpy(s,con_word[i+1]);
				break;
			}
		}
		if (s[0]=='T')
		{
			strcpy(status,"Stopped");
		}
		else if(s[0]=='R'){
			strcpy(status,"Running");	
		}
		else if(s[0]=='D'){
			strcpy(status,"Uninterruptible sleep");	
		}
		else if(s[0]=='S'){
			strcpy(status,"Sleeping");	
		}
		else{
			strcpy(status,"Zombie");	
		}

		printf("[%d] %s  %s[%d]\n",i,status, proc_name[i], proc_id[i] );
	}
}


void kjobs(char ** args)
{
	if (args[1]==NULL || args[2] == NULL)
	{
		printf("More arguments required\n");
		return ;
	}

	int jid = atoi(args[1]);
	int signal = atoi(args[2]);
	if(jid>=u)
		{
			printf("Jobs doesnt exist\n");
		}
		else
		{
			if (proc_id[jid]!=-1)
			kill(proc_id[jid],signal);
		}
		return 1 ;
}