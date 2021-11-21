
#include <stdio.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include "yyerror.h"

int yyerror(
	int* error,
	void* _,
	void* __,
	unsigned* line,
	const char* s)
{
	fprintf(stderr, "%s: line %u: %s\n", argv0, *line, s);
	
	*error = e_syntax_error;
	
	return 1;
}

