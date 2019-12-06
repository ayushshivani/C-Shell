#include "header.h"


int s_pinfo(char ** args)
{

	char ** con_word = malloc(sizeof(char)*1024);
	int pid;
	if (args[1]==NULL)
	{
		pid = getpid();
	}
	else
	{
		pid = atoi(args[1]);
	}
	char c[100];
	size_t size;
	sprintf(c,"/proc/%d/status",pid);
	printf("pid -- %d\n",pid );
	char file_content[100024];
	FILE *ftpr = fopen(c,"r");
	if (ftpr==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	else
	{
		fseek(ftpr,0,SEEK_SET);
		size =fread(file_content,sizeof(char),10000,ftpr);
		if (size<0)
		{
			printf("Cannot read the file\n");
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
			printf("Process Status -- %s\n",con_word[i+1] );
		}
		if (strcmp(con_word[i],"VmSize:")==0)
		{
			printf("- %s {Virtual Memory}\n",con_word[i+1] );
		}
	}

	char des[1024];
	memset(des,0,sizeof(des));
	sprintf(c,"/proc/%d/exe",pid);
	printf("- Executable Path - ");
	if (readlink(c,des,1024)==-1)
	{
		perror("readlink");
	}
	else
	{
		printf("%s\n",des );
	}
	fclose(ftpr);


}

