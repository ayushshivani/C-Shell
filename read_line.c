#include "header.h"

// functions read the input line
char * read_line()
{

	int buffer_size = 1024;
	char * buffer = malloc(sizeof(char)*buffer_size);
	int index =0;
	int c;
	if(buffer == NULL)
	{
		fprintf(stderr,"Memory Allocation Error\n");
		exit(EXIT_FAILURE);

	}

	while(1)
	{
		c = getchar();
		if ( c == EOF || c =='\n') 
		{
			// exit(EXIT_FAILURE);
			buffer[index++] = '\0';
			return buffer;
		}
		else
		{
			buffer[index++] = c;
			
		}

		if (index >=buffer_size)  //if the line is greaterthan the initial buffer size realloc the array
		{
			buffer_size += 1024;
			buffer = realloc(buffer,buffer_size);
			fprintf(stderr,"Memory Allocation Error\n");
			exit(EXIT_FAILURE);
		}
	}


}
