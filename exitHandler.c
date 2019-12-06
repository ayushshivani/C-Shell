#include "header.h"

int exitHandler(int x)
{
	ky = 1;
	fflush(stdout);
	return 1;
}

int signHandler(int x)
{
	by =1;
	return 1;
}