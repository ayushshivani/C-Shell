#include "header.h"



void shell_clock(char ** args)
{
	FILE *ftpr;
	int duration=0,interval=1;
	char path[100];
	char ** date_time = malloc(sizeof(char)*1024);
	char file_content[10035];
	size_t size;
	for (int i = 0; args[i]!=NULL ; ++i)
	{
		if (strcmp(args[i],"-n")==0)
		{
			duration = atoi(args[i+1]);
		}
		if (strcmp(args[i],"-t")==0)
		{
			interval = atoi(args[i+1]);
		}
	}
	int nof = duration/interval;
	strcpy(path,"/proc/driver/rtc");
	ftpr = fopen(path,"r");
	if (ftpr == NULL)
	{
		printf("Cannot Open File\n");
		exit(0);
	}
	else
	{
		while(nof--)
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

			date_time = parse_line(file_content);	
			for (int i = 0; date_time[i]!=NULL; ++i)
			{
				if (strcmp(date_time[i],"rtc_time")==0)
				{
					printf("%s ",date_time[i+2] );
				}
				if (strcmp(date_time[i],"rtc_date")==0)
				{
					printf("%s\n",date_time[i+2] );
				}
			}
			sleep(interval);
		}
	}
	fclose(ftpr);

}
