#include "header.h"

char *usr_name()
{
	struct utsname unameData;
	uname(&unameData);
	printf("%s\n",unameData.sysname );
}

char * print_dir(char cur_dir[])
{
	// res = malloc(sizeof(char)*1024);
	for (int i = 0; i <100 ; ++i)
	{
		res[i]='\0';
	}
	int j = 1, i=0;
	res[0] = '~';
	if (strlen(root)==strlen(cur_dir))
	{	
		return res;
	}
	else if(strlen(root)<strlen(cur_dir))
	{
		res[j++]= '/';

		i = strlen(root)+1;
		// printf("%s  %s\n",res,cur_dir);
		for (int k = i; k <strlen(cur_dir); ++k)
		{
		// printf("%d %d\n",k,j);	
			res[j++] = cur_dir[k];
		}
		// printf("%s\n",res );
		return res;
	}
	else
	{
		return cur_dir;
	}
}

void shell_prompt()
{
	//struct containing information about the system
	char cwd[1024];
	// free(cwd);
	struct utsname unameData;
	uname(&unameData);
	//finding the name user  
	char hostname[1023];
	hostname[1023] = '\0';
	int check = gethostname(hostname,1023);
	if (check)
	{
		perror("gethostname");
		exit(EXIT_FAILURE);
	}
	//getting curreny directory path
	getcwd(cwd,sizeof(cwd));
	
	printf("<%s@%s:%s>",hostname,unameData.sysname,print_dir(cwd));

}
