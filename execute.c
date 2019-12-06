#include "header.h"



//execute the commands

int execute(char ** args)
{
	int pipe =0;
	for (int i = 0; args[i]!=NULL; ++i)
	{
		for(int j=0;args[i][j]!='\0';j++)
		{
			// if (args[i][j]=='>' || args[i][j]=='<')
			// {
			// 	redirect = 1;
			// }
			if (args[i][j] == '|')
			{
				pipe = 1;
				// printf("12345\n");
			}
			// if (args[i][j]=='&')
			// {
			// 	background = 1;
			// }
		}

	}
	if (pipe ==1)
	{
		launch(args);
		return 1;
	}

	if (strcmp(args[0],"cd")==0)
	{
		build_cd(args);
	}
	else if (strcmp(args[0],"pwd")==0)
	{
		build_pwd(args);
	}
	else if (strcmp(args[0],"echo") == 0)
	{
		build_echo(args);
	}
	else if (strcmp(args[0],"ls")==0)
	{
		func_ls(args);
	}
	else if (strcmp(args[0],"pinfo")==0)
	{
		s_pinfo(args);
	}
	else if (strcmp(args[0],"remindme")==0)
	{
		remindme(args);
	}
	else if (strcmp(args[0],"clock")==0)
	{
		shell_clock(args);
	}
	else if (strcmp(args[0],"setenv")==0)
	{
		set_env(args);
	}
	else if (strcmp(args[0],"unsetenv")==0)
	{
		unset_env(args);
	}
	else if (strcmp(args[0],"jobs")==0)
	{
		jobs(args);
	}
	else if (strcmp(args[0],"fg")==0)
	{
		fg_command(args);
	}
	else if (strcmp(args[0],"bg")==0)
	{
		bg_command(args);
	}
	else if (strcmp(args[0],"quit")==0)
	{
		exit(0);
	}
	else if (strcmp(args[0],"overkill")==0)
	{
		overkill(args);
	}
	else if (strcmp(args[0],"kjob")==0)
	{
		kjobs(args);
	}
	else{
		launch(args);
	}
	return 1;

}