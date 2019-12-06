#include "header.h"

char **semi_parse_line(char *line)
{
	int buffer_size = 1024;
	char ** words = malloc(sizeof(char *)*buffer_size ); 
	if (!words)
	{				
		fprintf(stderr,"Memory Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	char * toke = strtok(line,";");
	int index = 0;
	while(toke !=NULL)
	{
		words[index] = toke;
		
		index++;   
		
		toke = strtok(NULL,";");
		if (index >=buffer_size)  //if the line is greaterthan the initial buffer size realloc the array
		{
			buffer_size += 1024;
			words = realloc(words,buffer_size);
			if (!words)
			{
			
				fprintf(stderr,"Memory Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}		
	}
	
	// printf("%s\n",*words);
	return words;

}