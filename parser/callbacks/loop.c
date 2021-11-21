
#include <stdio.h>

#include <debug.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include <statement/loopdo/struct.h>
#include <statement/loopdo/new.h>
#include <statement/inc.h>
#include <statement/free.h>

#include <next_ll/struct.h>
#include <next_ll/new.h>
#include <next_ll/append.h>
#include <next_ll/free.h>

#include "loop.h"

int loop_callback(
	struct statement** out_start, struct next_ll** out_nexts,
	unsigned line,
	struct expression* conditional,
	struct statement* body_start, struct next_ll* body_nexts)
{
	int error = 0;
	struct next_link* nlink;
	struct next_ll* nexts = NULL;
	struct loopdo_statement* loopdo = NULL;
	ENTER;
	
	error = 0
		?: new_loopdo_statement(&loopdo, line, conditional, body_start)
		?: new_next_ll(&nexts)
		?: next_ll_append(nexts, &loopdo->next);
	
	if (!body_nexts->n)
		fprintf(stderr, "%s: unreachable statement!\n", argv0),
		error = e_bad_input_file;
	else for (nlink = body_nexts->head; nlink; nlink = nlink->next)
		*nlink->element = ((struct statement*) loopdo);
	
	if (!error)
	{
		*out_start = (struct statement*) loopdo, loopdo = NULL;
		*out_nexts = nexts, nexts = NULL;
	}
	
	free_statement((struct statement*) loopdo);
	free_next_ll(nexts);
	free_next_ll(body_nexts);
	
	EXIT;
	return error;
}












