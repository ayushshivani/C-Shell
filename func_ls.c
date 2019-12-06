#include "header.h"

void dirt_perm(mode_t mode)
{
	char local_buff[16]={0};
	int i=0;
	// is directory ?
	if (S_ISDIR(mode)) {
	
		printf("d");
	}
	else {
		printf("-");	

	}
	i++;
    // user permissions
	if ((mode & S_IRUSR) == S_IRUSR) {

		printf("r");
	}
	else {
		printf("-");

	}
	i++;
	if ((mode & S_IWUSR) == S_IWUSR) {
		local_buff[i] = 'w';
		printf("w");
	}
	else {
		printf("-");
		local_buff[i] = '-';
	}
	i++;
	if ((mode & S_IXUSR) == S_IXUSR) {
		local_buff[i] = 'x';
		printf("x");
	}
	else {
		printf("-");
		local_buff[i] = '-';
	}
	i++;
	// group permissions
	if ((mode & S_IRGRP) == S_IRGRP) {
		local_buff[i] = 'r';
		printf("r");
	}
	else {
		local_buff[i] = '-';
		printf("-");
	}
	i++;
	if ((mode & S_IWGRP) == S_IWGRP) {
		local_buff[i] = 'w';
		printf("w");
	}
	else {
		local_buff[i] = '-';
		printf("-");
	}
	i++;
	if ((mode & S_IXGRP) == S_IXGRP) {
		local_buff[i] = 'x';
		printf("x");
	}
	else {
		printf("-");
		local_buff[i] = '-';
	}
	i++;
    // other permissions
	if ((mode & S_IROTH) == S_IROTH) {
		local_buff[i] = 'r';
		printf("r");
	}
	else {
		printf("-");
		local_buff[i] = '-';
	}
	i++;
	if ((mode & S_IWOTH) == S_IWOTH) {
		local_buff[i] = 'w';
		printf("w");
	}
	else {
		local_buff[i] = '-';
		printf("-");
	}
	i++;
	if ((mode & S_IXOTH) == S_IXOTH) {
		local_buff[i] = 'x';
		printf("x");
	}
	else {
		printf("-");
		local_buff[i] = '-';
	}
	
	printf("\t");

}



void func_ls(char ** args)
{
	DIR *dr;
	char cwd[200];
	struct dirent *sd;
	dr = opendir(getcwd(cwd,sizeof(cwd)));
	int flag_a = 0;
	int flag_l = 0;
	int flag_al = 0;
	int flag =0;
	char buffer[1024];
	char dir_name[1024];
	struct passwd *password;
	struct group *grp;
	struct tm *time;
	char date[200];
	for (int i = 1; args[i] != NULL; i++)
	{
		if (strcmp(args[i],"-a")==0)
		{
			flag_a = 1;				
		}
		if (strcmp(args[i],"-l" )==0)
		{
			flag_l =1;
		}
		if(strcmp(args[i],"-al")==0 || strcmp(args[i],"-la")==0)
		{
			flag_a =1;
			flag_l =1;
		}
		else
			flag=1;
	}
	if(flag==0)
	{
		// pwd();
		 getcwd(dir_name,sizeof(dir_name));
	}

	if (flag_l != 1)
	{
	
		if (flag_a == 1) // ls -a
		{
		
			while((sd=readdir(dr))!=NULL)
			{
				printf("%s\t",sd->d_name );
				printf("\n");
			}
		}
		else
		{
			while((sd=readdir(dr))!=NULL)
			{
				if (sd->d_name[0] == '.' )
				{
					continue;
				}
				else
				{
					printf("%s\t",sd->d_name );
										
				}
				printf("\n");
			}
			
		}
	}
	else
	{
		// find_permision()
		while((sd=readdir(dr))!=NULL)
		{
			if ( sd->d_name[0] == '.' && flag_a == 0)
			{
				continue;				
			}
			sprintf(buffer,"%s/%s",cwd,sd->d_name );
			// printf("%s \n",buffer );
			stat(buffer,&st);
			dirt_perm(st.st_mode);
			printf("%lu\t",st.st_nlink);
			if (getpwuid(st.st_uid)!= NULL)
			{
				password = getpwuid(st.st_uid);
				printf("%s\t",password->pw_name );
			}
			else
			{
				printf("%d\t",st.st_uid );
			}

			if ((grp = getgrgid(st.st_gid)) != NULL)
			{
				// grp = getgrgid(st.st_gid);
				printf("%s\t",grp->gr_name );
			}
			else
			{
				printf("%d\t",st.st_gid );
			}
			printf("%ld\t",st.st_size );
			time = localtime(&st.st_mtime);
			strftime(date,sizeof(date),"%b %d %H:%M",time);
			printf("%s\t%s\t",date,sd->d_name );
			printf("\n");
		}
	}	

}
