#include "header.h"

int main(int argc ,char *argv[])
{
	//for ctrl + c 
	// signal(SIGINT, signal_handler);
	root = getenv("PWD");
	int check;
	//main loop
	
	char * line ;
	char ** word_line;
	char ** command_line;
	while(1)
	{

		
		shell_prompt();  // display the shell prompt
		line  =read_line(); // read the lines 
		
		if (line[0] =='\0')
		{
			continue;
		}
		else
		{
			command_line =semi_parse_line(line);
			for (int i = 0; command_line[i]!=NULL ; ++i)
			{
				
				word_line = parse_line(command_line[i]);
				int k= 0;
			
				// printf("%s\n",word_line[0]);
				check = execute(word_line);
			
				check_background();
			}		
			free(line);
		}
	}	
}