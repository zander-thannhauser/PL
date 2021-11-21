
#include <stdlib.h>

#include <debug.h>

#include <statement/goto/new.h>

#include <next_ll/new.h>

#include <label_scope/lookup.h>

#include "goto.h"

int goto_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line,
	char* name,
	struct label_scope* lscope)
{
	int error = 0;
	ENTER;
	
	dpvs(name);
	
	error = 0
		?: new_goto_statement(
			(struct goto_statement**) out_start,
			line, label_scope_lookup(lscope, name))
		?: new_next_ll(out_nexts);
	
	free(name);
	
	EXIT;
	return error;
}















