#ifndef SHELL_H

#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/wait.h>



#define DELIM " \t\n"


//global; variables

char * root;
char hostname[1024];
char res[100];
int by ;
int ky ;

int proc_id[100];
char proc_name[100][100];
int u ;

struct stat st;


//functions
char *usr_name();
char * print_dir(char cur_dir[]);
void shell_prompt();
char * read_line();
char **semi_parse_line(char *line);
char **parse_line(char *line);
int build_cd(char ** args);
int build_pwd(char ** args);
int build_echo(char ** args);
void dirt_perm(mode_t mode);
void func_ls(char ** args);
int s_pinfo(char ** args);
int launch(char ** args);
char *name(int id);
void check_background();
void remindme(char ** args);
void shell_clock(char ** args);
int execute(char ** args);
int check_redirection(char ** args);
int shell_redirection(char ** args,int fd_in,int fd_out,int par);
void piping(char ** args);
void unset_env(char ** args);
void set_env(char ** args);
void jobs(char ** args);
void fg_command(char **args);
void bg_command(char ** args);
int overkill(char ** args);
int exitHandler(int x);
int signHandler(int x);
void kjobs(char ** args);


#endif
