
#include <stdio.h>
#include <stdlib.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include "smalloc.h"

int smalloc(void** ptr, size_t size)
{
	int error = 0;
	void* retval;
	ENTER;
	
	if (!(retval = malloc(size)))
		fprintf(stderr, "%s: malloc(size = %lu): %m\n", argv0, size),
		error = e_out_of_memory;
	else
		*ptr = retval;
	
	EXIT;
	return error;
}

