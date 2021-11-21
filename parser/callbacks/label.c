
#include <stdlib.h>
#include <stdio.h>

#include <debug.h>

#include <label_scope/declare.h>

#include <statement/free.h>

#include <next_ll/free.h>

#include "label.h"

int label_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	char* name,
	struct statement* inner_start,
	struct next_ll* inner_nexts,
	struct label_scope* label_scope)
{
	int error = 0;
	ENTER;
	
	error = label_scope_declare(label_scope, name, inner_start);
	
	if (!error)
	{
		*out_start = inner_start, inner_start = NULL;
		*out_nexts = inner_nexts, inner_nexts = NULL;
	}
	
	free_statement(inner_start);
	free_next_ll(inner_nexts);
	free(name);
	
	EXIT;
	return error;
}








