
#include <stdlib.h>

#include <debug.h>

#include <statement/goto/new.h>

#include <next_ll/new.h>

#include "stop.h"

int stop_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line)
{
	int error = 0;
	ENTER;
	
	error = 0
		?: new_goto_statement(
			(struct goto_statement**) out_start, line, NULL)
		?: new_next_ll(out_nexts);
	
	EXIT;
	return error;
}















