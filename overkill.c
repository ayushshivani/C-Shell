#include "header.h"

int overkill(char ** args)
{
	for (int i = 0; i < u; ++i)
	{
		if (proc_id[i]!=-1)
		kill(proc_id[i],15);
	}
	u =0 ;
	return 0;
}