
#include <string.h>

#include <debug.h>

#include "strstrip.h"

void strstrip(char** stringptr)
{
	char* ending;
	ENTER;
	
	char* string = *stringptr;
	
	dpvs(string);
	
	string += strspn(string, " \t\n\r");
	
	if ((ending = strpbrk(string, " \t\n\r")))
		*ending = '\0';
	
	*stringptr = string;
	
	EXIT;
}

